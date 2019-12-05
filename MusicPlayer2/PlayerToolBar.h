#pragma once
#include "CommonData.h"

// CPlayerToolBar
// �Ի�Ĺ�����

class CPlayerToolBar : public CStatic
{
	DECLARE_DYNAMIC(CPlayerToolBar)
public:
	CPlayerToolBar();
	virtual ~CPlayerToolBar();

    // ����һ����ť�������ִ��һ������
    // IconRes icon: ͼ����Դ
    // LPCTSTR strText: ͼ���Ҳ���ı�
    // LPCTSTR strToolTip: �����ʾ���ı�
    // UINT cmdId: �����ִ�е�����ID
    // bool showText: �Ƿ���ͼ���Ҳ���ʾ�ı�
    void AddToolButton(IconRes icon, LPCTSTR strText, LPCTSTR strToolTip, UINT cmdId, bool showText = false);

    // ����һ����ť������󵯳��˵�
    // IconRes icon: ͼ����Դ
    // LPCTSTR strText: ͼ���Ҳ���ı�
    // LPCTSTR strToolTip: �����ʾ���ı�
    // CMenu * pMenu: ����󵯳��Ĳ˵�
    // bool showText: �Ƿ���ͼ���Ҳ���ʾ�ı�
    void AddToolButton(IconRes icon, LPCTSTR strText, LPCTSTR strToolTip, CMenu* pMenu, bool showText = false);

    void SetIconSize(int size);
    void SetCmdReciveWindow(CWnd* pWnd);        //������Ӧ���߰�ť����Ĵ��ڣ���������ã���Ϊ�������ĸ�����

protected:
    struct ToolBtn
    {
        IconRes icon;           //ͼ��
        CString text;           //��ʾ�ı�
        bool show_text = false; //�Ƿ���ʾ�ı�
        UINT cmd_id;            //������͵�����ID
        CMenu* pMenu = nullptr; //����󵯳��Ĳ˵�
        bool is_cmd = true;     //�����������ǵ����˵�
        CString tooltip_text;   //�����ʾ�ı�
        CRect rect;				//��ť�ľ�������
        bool hover{ false };	//����Ƿ�ָ��ť
        bool pressed{ false };	//��ť�Ƿ���
        bool enable{ true };	//��ť�Ƿ�����
    };

    void AddToolTips();
    CWnd* GetCmdReciveWindow();

protected:
	CToolTipCtrl m_tool_tip;		//�ı���ʾ��
    std::vector<ToolBtn> m_buttons;
    ColorTable& m_theme_color;
    int m_icon_size = 20;
    int m_cur_btn_id = 100;
    bool m_first_draw = true;
    bool m_menu_poped_up = false;
    CWnd* m_pCmdReciveWnd = nullptr;

	DECLARE_MESSAGE_MAP()

	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void PreSubclassWindow();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
    afx_msg void OnMouseLeave();
    afx_msg void OnMouseHover(UINT nFlags, CPoint point);
protected:
    afx_msg LRESULT OnInitmenu(WPARAM wParam, LPARAM lParam);
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};

