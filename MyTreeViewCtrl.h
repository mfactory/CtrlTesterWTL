#pragma once

// <<< 参考資料 >>>
// [SAMPLE] TreeView でのカスタム描画方法を示したサンプル プログラム CustDTv
// http://support.microsoft.com/kb/248496/ja

using namespace WTL;
class CMyTreeViewCtrl
	: public CWindowImpl< CMyTreeViewCtrl, CTreeViewCtrl >
	, public CCustomDraw< CMyTreeViewCtrl >
{
public:
	CMyTreeViewCtrl(){}

	BEGIN_MSG_MAP( CMyTreeViewCtrl )
		MESSAGE_HANDLER( WM_CREATE, OnCreate )
		CHAIN_MSG_MAP_ALT( CCustomDraw< CMyTreeViewCtrl >, 1 )
	END_MSG_MAP()

// メッセージ
protected:
	LRESULT OnCreate( UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/ );

// オーバーライド
public:
	DWORD OnPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)			{ return CDRF_NOTIFYITEMDRAW; }
	DWORD OnPostPaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)		{ return CDRF_SKIPDEFAULT; }
	DWORD OnPreErase(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)			{ return CDRF_SKIPDEFAULT; }
	DWORD OnPostErase(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)		{ return CDRF_SKIPDEFAULT; }
	DWORD OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
	DWORD OnItemPostPaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)	{ return CDRF_SKIPDEFAULT; }
	DWORD OnItemPreErase(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)		{ return CDRF_SKIPDEFAULT; }
	DWORD OnItemPostErase(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)	{ return CDRF_SKIPDEFAULT; }
#if (_WIN32_IE >= 0x0400)
	DWORD OnSubItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)	{ return CDRF_SKIPDEFAULT; }
#endif // (_WIN32_IE >= 0x0400)
};
