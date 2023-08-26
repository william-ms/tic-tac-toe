#include <wx/wx.h>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxMenuBar* m_mainMenuBar = nullptr;
	wxMenu* m_menuGame = nullptr;
	wxMenu* m_menuHelp = nullptr;

	wxStatusBar* m_statusBar = nullptr;
	char m_msgStatusBar[200];

	wxGridSizer* gBoard = nullptr;

	wxButton* m_btnUpLeft;
	wxButton* m_btnUpMiddle;
	wxButton* m_btnUpRight;
	wxButton* m_btnMiddleLeft;
	wxButton* m_btnMiddleMiddle;
	wxButton* m_btnMiddleRight;
	wxButton* m_btnLowLeft;
	wxButton* m_btnLowMiddle;
	wxButton* m_btnLowRight;

	int board[3][3];
	int player;
	int turnCounter;
	int victorious;

public:
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	void EnableGrid();
	void DisableGrid();
	void EndGame();

	void initBoard();
	int checkBoard();

	void OnBtnUpLeftClick(wxCommandEvent& event);
	void OnBtnUpMiddleClick(wxCommandEvent& event);
	void OnBtnUpRightClick(wxCommandEvent& event);
	void OnBtnMiddleLeftClick(wxCommandEvent& event);
	void OnBtnMiddleMiddleClick(wxCommandEvent& event);
	void OnBtnMiddleRightClick(wxCommandEvent& event);
	void OnBtnLowLeftClick(wxCommandEvent& event);
	void OnBtnLowMiddleClick(wxCommandEvent& event);
	void OnBtnLowRightClick(wxCommandEvent& event);

	void OnBtnUpLeftEnterWindow(wxCommandEvent& event);
	void OnBtnUpMiddleEnterWindow(wxCommandEvent& event);
	void OnBtnUpRightEnterWindow(wxCommandEvent& event);
	void OnBtnMiddleLeftEnterWindow(wxCommandEvent& event);
	void OnBtnMiddleMiddleEnterWindow(wxCommandEvent& event);
	void OnBtnMiddleRightEnterWindow(wxCommandEvent& event);
	void OnBtnLowLeftEnterWindow(wxCommandEvent& event);
	void OnBtnLowMiddleEnterWindow(wxCommandEvent& event);
	void OnBtnLowRightEnterWindow(wxCommandEvent& event);

	void OnBtnUpLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnUpMiddleLeaveWindow(wxCommandEvent& event);
	void OnBtnUpRightLeaveWindow(wxCommandEvent& event);
	void OnBtnMiddleLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnMiddleMiddleLeaveWindow(wxCommandEvent& event);
	void OnBtnMiddleRightLeaveWindow(wxCommandEvent& event);
	void OnBtnLowLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnLowMiddleLeaveWindow(wxCommandEvent& event);
	void OnBtnLowRightLeaveWindow(wxCommandEvent& event);
};