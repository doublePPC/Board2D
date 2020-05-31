/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Graphics.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once
#include "..\\Windows\\ChiliWin.h"
#include <d3d11.h>
#include <wrl.h>
#include "..\\Chili_Other_Stuff\\ChiliException.h"
#include "..\\Generic\\Colors.h"
#include "..\\Generic\\Vec2.h"
#include "Sprite.h"
#include "PixelEffect.h"

class Graphics
{
public:
	class Exception : public ChiliException
	{
	public:
		Exception( HRESULT hr,const std::wstring& note,const wchar_t* file,unsigned int line );
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x,y,z;		// position
		float u,v;			// texcoords
	};
public:
	Graphics( class HWNDKey& key );
	Graphics( const Graphics& ) = delete;
	Graphics& operator=( const Graphics& ) = delete;
	void EndFrame();
	void BeginFrame();
	void DrawRect(const Vec2& TopLeft, const Vec2& BottomRight, Color c);
	void DrawSprite(const Vec2& pos, const Surface& surf, const Vec2& visibleTL, const Vec2& visibleBR, Color transp, bool withTransp);
	void DrawSheetFragment(const Vec2& pos, const Surface& surf, const Vec2& visibleTL, const Vec2& visibleBR, Color transp, int startShX, int startShY);
	template <typename E>
	void DrawSpriteSheet(const Vec2& pos, const Vec2& visTL, const Vec2& visBR, const Surface& surf, int startShX, int startShY, E effect)
	{
		const Vec2 start = Vec2(visTL.x - pos.x, visTL.y - pos.y);
		const Vec2 end = Vec2(visBR.x - visTL.x, visBR.y - visTL.y);

		for (int y = 0; y <= int(end.y); y++)
		{
			for (int x = 0; x <= int(end.x); x++)
			{
				Color colorToDraw = effect(GetPixel(int(visTL.x) + x, int(visTL.y) + y), surf.getPixel(x + int(start.x) + startShX, y + int(start.y) + startShY));
				PutPixel(int(visTL.x) + x, int(visTL.y) + y, colorToDraw);
			}
		}
	}
	void PutPixel( int x,int y,int r,int g,int b )
	{
		PutPixel( x,y,{ unsigned char( r ),unsigned char( g ),unsigned char( b ) } );
	}
	void PutPixel( int x,int y,Color c );
	Color GetPixel(int x, int y) const;
	~Graphics();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color*                                              pSysBuffer = nullptr;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};