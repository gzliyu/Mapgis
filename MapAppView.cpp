
// MapAppView.cpp: CMapAppView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MapApp.h"
#endif

#include "MapAppDoc.h"
#include "MapAppView.h"
#include"CGeoMap.h"
#include"CDlgOverlay.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapAppView

IMPLEMENT_DYNCREATE(CMapAppView, CView)

BEGIN_MESSAGE_MAP(CMapAppView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMapAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_OVERLAY, &CMapAppView::OnCall_Overlay)
END_MESSAGE_MAP()

// CMapAppView 构造/析构

CMapAppView::CMapAppView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMapAppView::~CMapAppView()
{
}

BOOL CMapAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

void CMapAppView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CRect rc;
	GetClientRect(&rc);

	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetViewportOrg((rc.left + rc.right) / 2, (rc.top + rc.bottom) / 2);
	pDC->SetWindowOrg(0, 0);
	pDC->SetViewportExt(rc.Width(), -rc.Height());
	pDC->SetWindowExt(nWidth, nHeight);


}

// CMapAppView 绘图

void CMapAppView::OnDraw(CDC* pDC)
{
	CMapAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CGeoMap* pMap = pDoc->m_ptMap;
	pMap->nWidth = &nWidth;
	pMap->nHeight = &nHeight;
	if (pMap->m_nLayerNum) {
		printf("%d\n", pMap->m_nLayerNum);
		pMap->Draw(pDC);
	}
	
}


// CMapAppView 打印


void CMapAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMapAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMapAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMapAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMapAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMapAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMapAppView 诊断

#ifdef _DEBUG
void CMapAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMapAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapAppDoc* CMapAppView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapAppDoc)));
	return (CMapAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMapAppView 消息处理程序





void CMapAppView::OnCall_Overlay()
{
	// TODO: 在此添加命令处理程序代码
	CDlgOverlay dlg;
	if (dlg.DoModal() == IDCANCEL)
	{
		return;
	}
	CMapAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CGeoMap* pMap = pDoc->m_ptMap;
	//pMap->overlay(dlg.m_SubKey, dlg.m_ClipKey, dlg.m_Select);
	pMap->overlay(&dlg);
	//UpdateWindow();
	RedrawWindow();


}
