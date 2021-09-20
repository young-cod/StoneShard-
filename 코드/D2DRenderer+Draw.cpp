#include "stdafx.h"
#include "D2DRenderer.h"



/**********************************************************************************************
## RenderText ##
@@ int x : x ��ǥ
@@ int y : y ��ǥ
@@ wstring text : �׸� �ؽ�Ʈ
@@ int size : ��Ʈ ������
@@ DefaultBrush brush : �׸� �귯�� = DefaultBrush::Black
@@ DWRITE_TEXT_ALIGNMENT align : ���� �ɼ� = DWRITE_TEXT_ALIGNMENT_LEADING
@@ bool isRelative : ī�޶� ���� ���� = false
@@ wstring font : ��Ʈ = �������

�⺻ �����ص� �귯���� �ؽ�Ʈ ������
************************************************************************************************/
void D2DRenderer::RenderText(const int x, const int y, const wstring& text, const int size,
	const DefaultBrush& defaultBrush, const DWRITE_TEXT_ALIGNMENT& align, const wstring& font)
{
	POINT pos;
	pos.x= x;
	pos.y = y;

	IDWriteTextLayout* layout = nullptr;
	HRESULT hr = this->mDWFactory->CreateTextLayout
	(
		text.c_str(),
		text.length(),
		this->mFontList[font],
		(float)text.length() * size,
		(float)size,
		&layout
	);
	assert(SUCCEEDED(hr));

	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = text.length();

	layout->SetFontSize((float)size, range);
	layout->SetTextAlignment(align);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	mD2DRenderTarget->DrawTextLayout(D2D1::Point2F(pos.x, pos.y), layout,
		mDefaultBrushList[(UINT)defaultBrush]);

	NEW_SAFE_RELEASE(layout);
}
/**********************************************************************************************
## RenderText ##
@@ int x : �׸���ǥ
@@ int y : �׸���ǥ
@@ wstring text : �׸� �ؽ�Ʈ
@@ COLORREF color : RGB�÷�
@@ float alpha : ���� ��
@@ int size : ��Ʈ ������
@@ DWRITE_TEXT_ALIGNMENT align : ���Ŀɼ�
@@ bool isRelative : ī�޶� ���� ����
@@ wstring font : ��Ʈ

���ο� �귯�� ������ ������
************************************************************************************************/
void D2DRenderer::RenderText(const int x, const int y, const wstring& text, const COLORREF& color,
	const float alpha, const int size, const DWRITE_TEXT_ALIGNMENT& align, const wstring& font)
{
	POINT pos;
	pos.x = x;
	pos.y = y;

	IDWriteTextLayout* layout = nullptr;
	//�ؽ�Ʈ ���̾ƿ� ����
	mDWFactory->CreateTextLayout(
		text.c_str(),
		text.length(),
		mFontList[font],
		(float)text.length() * size,
		(float)size,
		&layout
	);

	//���̾ƿ� �¾�
	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = text.length();
	layout->SetFontSize((float)size, range);
	layout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	layout->SetTextAlignment(align);

	//�귯�� ����
	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color, alpha), &brush);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	mD2DRenderTarget->DrawTextLayout(D2D1::Point2F(pos.x, pos.y), layout, brush);

	NEW_SAFE_RELEASE(brush);
	NEW_SAFE_RELEASE(layout);
}
/**********************************************************************************************
## RenderTextField ##
@@ int x : �׸� ��ǥ
@@ int y : �׸� ��ǥ
@@ wstring text : �׸� �ؽ�Ʈ
@@ int size : ��Ʈ ������
@@ int width : ���� ���α���
@@ int heifht : ���� ���α���
@@ DefaultBrush brush : �⺻ ���� �귯��
@@ DWRITE_TEXT_ALIGNMENT align : ���� �ɼ�
@@ bool isRalative : ī�޶� ���� ����
@@ wstring font : ��Ʈ

���������� �⺻ �귯���� ���� ���
************************************************************************************************/
void D2DRenderer::RenderTextField(const int x, const int y, const wstring& text, const int size,
	const int width, const int height, const DefaultBrush& defaultBrush, const DWRITE_TEXT_ALIGNMENT& align, const wstring& font)
{
	POINT pos;
	pos.x = x;
	pos.y = y;

	IDWriteTextLayout* layout = nullptr;
	mDWFactory->CreateTextLayout(
		text.c_str(),
		text.length(),
		mFontList[font],
		(float)width,
		(float)height,
		&layout
	);

	//���̾ƿ� �¾�
	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = text.length();
	layout->SetFontSize((float)size, range);

	layout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	layout->SetTextAlignment(align);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	mD2DRenderTarget->DrawTextLayout(D2D1::Point2F(pos.x, pos.y), layout, mDefaultBrushList[(UINT)defaultBrush]);

	NEW_SAFE_RELEASE(layout);
}
/**********************************************************************************************
## RenderText ##
@@ int x : �׸� ��ǥ
@@ int y : �׸� ��ǥ
@@ wstring text : �׸� �ؽ�Ʈ
@@ COLORREF color : �׸� �÷�
@@ int size : ��Ʈ ������
@@ int width : ���� ���� ����
@@ int height : ���� ���� ����
@@ float alpha : ���İ�
@@ DWRITE_TEXT_ALIGNMENT align : ���� �ɼ�
@@ bool isRelative : ī�޶� ��������
@@ wstring font : ��Ʈ

�����ȿ��� ���ο� �귯���� �����ؼ� ��Ʈ���
************************************************************************************************/
void D2DRenderer::RenderTextField(const int x, const int y, const wstring& text, const COLORREF& color,
	const int size, const int width, const int height, const float alpha, const DWRITE_TEXT_ALIGNMENT& align, const wstring& font)
{
	POINT pos;
	pos.x = x;
	pos.y = y;

	IDWriteTextLayout* layout = nullptr;
	mDWFactory->CreateTextLayout(
		text.c_str(),
		text.length(),
		mFontList[font],
		(float)width,
		(float)height,
		&layout
	);

	//���̾ƿ� �¾�
	DWRITE_TEXT_RANGE range;
	range.startPosition = 0;
	range.length = text.length();
	layout->SetFontSize((float)size, range);

	layout->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
	layout->SetTextAlignment(align);

	//�귯�� ����
	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color, alpha), &brush);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	mD2DRenderTarget->DrawTextLayout(D2D1::Point2F((float)x, (float)y), layout, brush);

	NEW_SAFE_RELEASE(layout);
	NEW_SAFE_RELEASE(brush);
}
/**********************************************************************************************
## DrawLine ##
@@ Vector2 start : ���� ��
@@ Vector2 end : �� ��
@@ D2D1::ColorF::Enum color : ����
@@ float alpha : ���� ��
@@ bool isRelative : ī�޶� ���� ����
@@ float strokeWidth : �� ����
************************************************************************************************/
void D2DRenderer::DrawLine(const POINT& start, const POINT& end, const D2D1::ColorF::Enum& color,
	const float alpha, const float strokeWidth)
{
	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color, alpha), &brush);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	POINT startPos = start;
	POINT endPos = end;

	target->DrawLine(D2D1::Point2F(startPos.x, startPos.y), D2D1::Point2F(endPos.x, endPos.y), brush, strokeWidth);
	NEW_SAFE_RELEASE(brush);
}
/**********************************************************************************************
## RenderText ##
@@ Vector2 start : ���� ��
@@ Vector2 end : �� ��
@@ DefaultBrush brush : �⺻ ���� �귯��
@@ bool isRelative : ī�޶� ���� ����
@@ float stroke : �� ����
***********************************************************************************************/
void D2DRenderer::DrawLine(const POINT& start, const POINT& end, const DefaultBrush& defaultBrush, const float strokeWidth)
{
	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	POINT startPos = start;
	POINT endPos = end;

	mD2DRenderTarget->DrawLine(D2D1::Point2F(startPos.x, startPos.y),
		D2D1::Point2F(endPos.x, endPos.y), mDefaultBrushList[(UINT)defaultBrush], strokeWidth);

}
/**********************************************************************************************
## DrawRectangle ##
@@ FloatRect rc : ��Ʈ
@@ D2D1::ColorF::Enum color : �÷�
@@ float alpha : ���� ��
@@ bool isRelative : ī�޶� ��������
@@ float strokeWidth : �� ����
************************************************************************************************/
void D2DRenderer::DrawRectangle(const RECT& rc, const D2D1::ColorF::Enum& color,
	const float alpha, const float strokeWidth)
{
	RECT rect = rc;

	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color, alpha), &brush);

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	mD2DRenderTarget->DrawRectangle(D2D1::RectF((float)rect.left, (float)rect.top, (float)rect.right, (float)rect.bottom),
		brush, strokeWidth);

	NEW_SAFE_RELEASE(brush);
}
/**********************************************************************************************
## DrawRectangle ##
@@ FloatRect rc : �׸� ��Ʈ
@@ DefaultBrush brush : �׸� �귯��
@@ bool isRelative : ī�޶� ���� ����
@@ float stroke : �� ����
************************************************************************************************/
void D2DRenderer::DrawRectangle(const RECT& rc, bool renderType, const DefaultBrush& defaultBrush, const float strokeWidth, const float angle)
{
	RECT rect = rc;

	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(angle, D2D1::Point2F(rc.left, rc.top));

	mD2DRenderTarget->SetTransform(rotateMatrix);

	if (renderType)mD2DRenderTarget->DrawRectangle(D2D1::RectF((float)rect.left, (float)rect.top, (float)rect.right, (float)rect.bottom),
		mDefaultBrushList[(UINT)defaultBrush], strokeWidth);
	else target->DrawRectangle(D2D1::RectF((float)rect.left, (float)rect.top, (float)rect.right, (float)rect.bottom),
		mDefaultBrushList[(UINT)defaultBrush], strokeWidth);
}


/**********************************************************************************************
## FillRectagle ##
@@ FloatRect rc : �׸� ��Ʈ
@@ D2D1::ColorF::Enum color : D2D�÷�
@@ float alpha  : ���� ��
@@ bool isRelative : ī�޶� ���� ����
************************************************************************************************/
void D2DRenderer::FillRectangle(const RECT& rc, const D2D1::ColorF::Enum& color, const float alpha)
{
	RECT rect = rc;

	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color, alpha), &brush);
	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	mD2DRenderTarget->FillRectangle(D2D1::RectF((float)rect.left, (float)rect.top, (float)rect.right, (float)rect.bottom), brush);

	NEW_SAFE_RELEASE(brush);
}
/**********************************************************************************************
## FillRectangle  ##
@@ FloatRec rc : ũ�� ��Ʈ
@@ DefaultBrush brush : �귯��
@@ bool isRelative : ī�޶� ��������
************************************************************************************************/
void D2DRenderer::FillRectangle(const RECT& rc, const DefaultBrush& defaultBrush, float angle)
{
	RECT rect = rc;

	mD2DRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	D2D1::Matrix3x2F rotateMatrix = D2D1::Matrix3x2F::Rotation(angle, D2D1::Point2F(rc.left, rc.top));

	mD2DRenderTarget->SetTransform(rotateMatrix);

	mD2DRenderTarget->FillRectangle(D2D1::RectF((float)rect.left, (float)rect.top, (float)rect.right, (float)rect.bottom),
		mDefaultBrushList[(UINT)defaultBrush]);
}

void D2DRenderer::DrawEllipse(const int x, const int y, const float radius, const D2D1::ColorF color, const float alpha, const float strokeWidth)
{
	D2D1_POINT_2F point = D2D1::Point2F(x, y);

	D2D1_ELLIPSE el = D2D1::Ellipse(point, radius, radius);

	ID2D1SolidColorBrush* brush;
	D2DRENDERTARGET->CreateSolidColorBrush(color, &brush);

	D2DRENDERTARGET->DrawEllipse(el, brush);

	NEW_SAFE_RELEASE(brush);
}

void D2DRenderer::DrawEllipse(const D2D1_POINT_2F & point, const float radius, const D2D1::ColorF color, const float alpha, const float strokeWidth)
{
	D2D1_ELLIPSE el = D2D1::Ellipse(point, radius, radius);
	ID2D1SolidColorBrush* brush;
	D2DRENDERTARGET->CreateSolidColorBrush(color, &brush);

	D2DRENDERTARGET->DrawEllipse(el, brush);

	NEW_SAFE_RELEASE(brush);
}

void D2DRenderer::FillEllipse(const int x, const int y, const float radius, const D2D1::ColorF color, const float alpha)
{
	D2D1_POINT_2F point = D2D1::Point2F(x, y);

	D2D1_ELLIPSE el = D2D1::Ellipse(point, radius, radius);

	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(color, &brush);

	mD2DRenderTarget->FillEllipse(el, brush);

	NEW_SAFE_RELEASE(brush);
}

void D2DRenderer::FillEllipse(const D2D1_POINT_2F& point,const float radius, const D2D1::ColorF color, const float alpha)
{
	D2D1_ELLIPSE el = D2D1::Ellipse(point, radius, radius);

	ID2D1SolidColorBrush* brush;
	mD2DRenderTarget->CreateSolidColorBrush(color, &brush);

	mD2DRenderTarget->FillEllipse(el, brush);

	NEW_SAFE_RELEASE(brush);
}
