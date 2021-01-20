
// MapAppView.h: CMapAppView 类的接口
//

#pragma once


class CMapAppView : public CView
{
protected: // 仅从序列化创建
	CMapAppView() noexcept;
	DECLARE_DYNCREATE(CMapAppView)

// 特性
public:
	CMapAppDoc* GetDocument() const;

// 操作
public:
	int nWidth = 10000;
	int nHeight = 18000;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMapAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCall_Overlay();
};

#ifndef _DEBUG  // MapAppView.cpp 中的调试版本
inline CMapAppDoc* CMapAppView::GetDocument() const
   { return reinterpret_cast<CMapAppDoc*>(m_pDocument); }
#endif

