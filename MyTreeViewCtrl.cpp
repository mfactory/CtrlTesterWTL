#include "StdAfx.h"
#include "MyTreeViewCtrl.h"

#include <uxtheme.h>
#include <tmschema.h>

#pragma comment(lib, "UxTheme.lib")

LRESULT CMyTreeViewCtrl::OnCreate( UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled )
{
	bHandled = FALSE;

	::SetWindowTheme( m_hWnd, L"explorer", NULL );

	return S_OK;
}


DWORD CMyTreeViewCtrl::OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW lpNMCustomDraw)
{
	LPNMTVCUSTOMDRAW pNMTVCD = reinterpret_cast< LPNMTVCUSTOMDRAW >( lpNMCustomDraw );

	HTREEITEM hItem = (HTREEITEM) pNMTVCD->nmcd.dwItemSpec;
	CDCHandle dc = pNMTVCD->nmcd.hdc;
	dc.SetBkMode( TRANSPARENT );

	CRect rcClient;
	GetClientRect( &rcClient );

	CRect rcItem;
	GetItemRect( hItem, &rcItem, TRUE );

	if ( ( pNMTVCD->nmcd.uItemState & CDIS_SELECTED ) == CDIS_SELECTED )
	{
		CRect rcItemLine = rcItem;
		rcItemLine.left = rcClient.left;
		rcItemLine.right = rcClient.right;

		HTHEME hTheme = ::OpenThemeData( m_hWnd, L"TREEVIEW" );

		::DrawThemeBackground( hTheme, dc.m_hDC, TVP_TREEITEM, TREIS_SELECTED, &rcItemLine, &rcItemLine );

		::CloseThemeData( hTheme );
	}

	CString strItem;
	GetItemText( hItem, strItem );

	dc.SetTextColor( RGB( 0, 0, 0 ) );
	dc.TextOut( rcItem.left, rcItem.top, strItem);

	return CDRF_SKIPDEFAULT;
}
