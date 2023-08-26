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
	wxButton* m_buttons[3][3];

	int board[3][3];
	int player;
	int turnCounter;
	int victorius;

	int idCurrent;
	int idBtn;

public:
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	void OnBtnClick(wxCommandEvent& event);
	void OnBtnEnterWindow(wxCommandEvent& event);

	void EnableGrid();
	void DisableGrid();
	void EndGame();

	void initBoard();
	int checkBoard();
};