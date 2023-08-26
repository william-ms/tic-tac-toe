#include "cMain.h"

enum
{
	ID_NewGame = 1
};

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Tic Tac Toe", wxPoint(0, 0), wxSize(600, 600))
{
	//Adicionar barra de menu
	m_mainMenuBar = new wxMenuBar(0);
	m_menuGame = new wxMenu();
	m_menuHelp = new wxMenu();

	m_mainMenuBar->Append(m_menuGame, "Game");
	m_mainMenuBar->Append(m_menuHelp, "Help");

	m_menuGame->Append(ID_NewGame, "&New Game\tCtrl-N", "Start a new match");
	m_menuGame->AppendSeparator();
	m_menuGame->Append(wxID_EXIT);

	m_menuHelp->Append(wxID_ABOUT);

	this->SetMenuBar(m_mainMenuBar);

	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	wxGridSizer* gBoard = new wxGridSizer(3, 3, 0, 0);
	gBoard->SetMinSize(500, 500);

	m_btnUpLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpLeft->SetFont(font);
	gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);

	m_btnUpMiddle = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpMiddle->SetFont(font);
	gBoard->Add(m_btnUpMiddle, 0, wxALL | wxEXPAND, 5);

	m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnUpRight->SetFont(font);
	gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);

	m_btnMiddleLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMiddleLeft->SetFont(font);
	gBoard->Add(m_btnMiddleLeft, 0, wxALL | wxEXPAND, 5);

	m_btnMiddleMiddle = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMiddleMiddle->SetFont(font);
	gBoard->Add(m_btnMiddleMiddle, 0, wxALL | wxEXPAND, 5);

	m_btnMiddleRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMiddleRight->SetFont(font);
	gBoard->Add(m_btnMiddleRight, 0, wxALL | wxEXPAND, 5);

	m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowLeft->SetFont(font);
	gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);

	m_btnLowMiddle = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowMiddle->SetFont(font);
	gBoard->Add(m_btnLowMiddle, 0, wxALL | wxEXPAND, 5);

	m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowRight->SetFont(font);
	gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);

	this->SetSizer(gBoard);
	this->Layout();

	m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	DisableGrid();
	SetStatusText("Go to New Game to start a match");

	Bind(wxEVT_MENU, &cMain::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &cMain::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &cMain::OnAbout, this, wxID_ABOUT);

	m_btnUpLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnUpLeftClick), NULL, this);
	m_btnUpMiddle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnUpMiddleClick), NULL, this);
	m_btnUpRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnUpRightClick), NULL, this);

	m_btnMiddleLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnMiddleLeftClick), NULL, this);
	m_btnMiddleMiddle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnMiddleMiddleClick), NULL, this);
	m_btnMiddleRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnMiddleRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnLowLeftClick), NULL, this);
	m_btnLowMiddle->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnLowMiddleClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnLowRightClick), NULL, this);

	m_btnUpLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnUpLeftEnterWindow), NULL, this);
	m_btnUpMiddle->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnUpMiddleEnterWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnUpRightEnterWindow), NULL, this);

	m_btnMiddleLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleLeftEnterWindow), NULL, this);
	m_btnMiddleMiddle->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleMiddleEnterWindow), NULL, this);
	m_btnMiddleRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleRightEnterWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnLowLeftEnterWindow), NULL, this);
	m_btnLowMiddle->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnLowMiddleEnterWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnLowRightEnterWindow), NULL, this);

	m_btnUpLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnUpLeftLeaveWindow), NULL, this);
	m_btnUpMiddle->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnUpMiddleLeaveWindow), NULL, this);
	m_btnUpRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnUpRightLeaveWindow), NULL, this);

	m_btnMiddleLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleLeftLeaveWindow), NULL, this);
	m_btnMiddleMiddle->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleMiddleLeaveWindow), NULL, this);
	m_btnMiddleRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnMiddleRightLeaveWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnLowLeftLeaveWindow), NULL, this);
	m_btnLowMiddle->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnLowMiddleLeaveWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_LEAVE_WINDOW, wxCommandEventHandler(cMain::OnBtnLowRightLeaveWindow), NULL, this);
}

cMain::~cMain()
{

}


void cMain::OnNewGame(wxCommandEvent& event)
{
	EnableGrid();
	initBoard();
	SetStatusText("It is Player 1's turn!");
}

void cMain::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void cMain::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a Tic Tac Toe Example in C/C++", "About Tic Tac Toe", wxOK | wxICON_INFORMATION);
}

void cMain::EnableGrid()
{
	m_btnUpLeft->Enable();
	m_btnUpMiddle->Enable();
	m_btnUpRight->Enable();
	m_btnMiddleLeft->Enable();
	m_btnMiddleMiddle->Enable();
	m_btnMiddleRight->Enable();
	m_btnLowLeft->Enable();
	m_btnLowMiddle->Enable();
	m_btnLowRight->Enable();

	m_btnUpLeft->SetLabelText("");
	m_btnUpMiddle->SetLabelText("");
	m_btnUpRight->SetLabelText("");
	m_btnMiddleLeft->SetLabelText("");
	m_btnMiddleMiddle->SetLabelText("");
	m_btnMiddleRight->SetLabelText("");
	m_btnLowLeft->SetLabelText("");
	m_btnLowMiddle->SetLabelText("");
	m_btnLowRight->SetLabelText("");
}

void cMain::DisableGrid()
{
	m_btnUpLeft->Disable();
	m_btnUpMiddle->Disable();
	m_btnUpRight->Disable();
	m_btnMiddleLeft->Disable();
	m_btnMiddleMiddle->Disable();
	m_btnMiddleRight->Disable();
	m_btnLowLeft->Disable();
	m_btnLowMiddle->Disable();
	m_btnLowRight->Disable();

	m_btnUpLeft->SetLabelText("");
	m_btnUpMiddle->SetLabelText("");
	m_btnUpRight->SetLabelText("");
	m_btnMiddleLeft->SetLabelText("");
	m_btnMiddleMiddle->SetLabelText("");
	m_btnMiddleRight->SetLabelText("");
	m_btnLowLeft->SetLabelText("");
	m_btnLowMiddle->SetLabelText("");
	m_btnLowRight->SetLabelText("");
}

void cMain::EndGame()
{
	char mensagem[200] = "";

	if (victorious == 0)
	{
		strcpy(mensagem, "TIED MATCH!");
	}
	else
	{
		if (victorious == 1)
		{
			strcpy(mensagem, "X - Player 1 wins!");
		}
		else
		{
			if (victorious == 2)
			{
				strcpy(mensagem, "O - Player 2 wins!");
			}
		}
	}

	strcat(mensagem, "Play again?");
	if (wxMessageBox(mensagem, "End of match!", wxYES_NO | wxICON_INFORMATION) == wxYES)
	{
		initBoard();
		EnableGrid();
	}
	else
	{
		Close(true);
	}
}

void cMain::initBoard()
{
	int i, j;
	player = 1;
	turnCounter = 0;
	victorious = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}
}

int cMain::checkBoard()
{
	int i, j, p1, p2;

	//Verificar linhas
	for (i = 0; i < 3; i++)
	{
		p1 = 0;
		p2 = 0;

		for (j = 0; j < 3; j++)
		{
			if (board[i][j] == 1)
			{
				p1++;
			}
			else if (board[i][j] == 2)
			{
				p2++;
			}
		}

		if (p1 == 3)
		{
			return 1;
		}
		else if (p2 == 3)
		{
			return 2;
		}
	}

	//Verificar colunas
	for (j = 0; j < 3; j++)
	{
		p1 = 0;
		p2 = 0;

		for (i = 0; i < 3; i++)
		{
			if (board[i][j] == 1)
			{
				p1++;
			}
			else if (board[i][j] == 2)
			{
				p2++;
			}
		}

		if (p1 == 3)
		{
			return 1;
		}
		else if (p2 == 3)
		{
			return 2;
		}
	}


	//Verificar diagonal principal
	p1 = 0;
	p2 = 0;
	for (i = 0, j = 0; i < 3; i++, j++)
	{
		if (board[i][j] == 1)
		{
			p1++;
		}
		else if (board[i][j] == 2)
		{
			p2++;
		}

		if (p1 == 3)
		{
			return 1;
		}
		else if (p2 == 3)
		{
			return 2;
		}
	}

	//Verificar diagonal secundária
	p1 = 0;
	p2 = 0;
	for (i = 0, j = 2; i < 3; i++, j--)
	{
		if (board[i][j] == 1)
		{
			p1++;
		}
		else if (board[i][j] == 2)
		{
			p2++;
		}

		if (p1 == 3)
		{
			return 1;
		}
		else if (p2 == 3)
		{
			return 2;
		}
	}

	//se ninguém ganhou
	return 0;
}

void cMain::OnBtnUpLeftClick(wxCommandEvent& event)
{
	if (m_btnUpLeft->IsEnabled())
	{
		board[0][0] = player;
		m_btnUpLeft->Disable();

		if (player == 1)
		{
			m_btnUpLeft->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnUpLeft->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnUpMiddleClick(wxCommandEvent& event)
{
	if (m_btnUpMiddle->IsEnabled())
	{
		board[0][1] = player;
		m_btnUpMiddle->Disable();

		if (player == 1)
		{
			m_btnUpMiddle->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnUpMiddle->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnUpRightClick(wxCommandEvent& event)
{
	if (m_btnUpRight->IsEnabled())
	{
		board[0][2] = player;
		m_btnUpRight->Disable();

		if (player == 1)
		{
			m_btnUpRight->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnUpRight->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}

void cMain::OnBtnMiddleLeftClick(wxCommandEvent& event)
{
	if (m_btnMiddleLeft->IsEnabled())
	{
		board[1][0] = player;
		m_btnMiddleLeft->Disable();

		if (player == 1)
		{
			m_btnMiddleLeft->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnMiddleLeft->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnMiddleMiddleClick(wxCommandEvent& event)
{
	if (m_btnMiddleMiddle->IsEnabled())
	{
		board[1][1] = player;
		m_btnMiddleMiddle->Disable();

		if (player == 1)
		{
			m_btnMiddleMiddle->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnMiddleMiddle->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnMiddleRightClick(wxCommandEvent& event)
{
	if (m_btnMiddleRight->IsEnabled())
	{
		board[1][2] = player;
		m_btnMiddleRight->Disable();

		if (player == 1)
		{
			m_btnMiddleRight->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnMiddleRight->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}

void cMain::OnBtnLowLeftClick(wxCommandEvent& event)
{
	if (m_btnLowLeft->IsEnabled())
	{
		board[2][0] = player;
		m_btnLowLeft->Disable();

		if (player == 1)
		{
			m_btnLowLeft->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnLowLeft->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnLowMiddleClick(wxCommandEvent& event)
{
	if (m_btnLowMiddle->IsEnabled())
	{
		board[2][1] = player;
		m_btnLowMiddle->Disable();

		if (player == 1)
		{
			m_btnLowMiddle->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnLowMiddle->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}
void cMain::OnBtnLowRightClick(wxCommandEvent& event)
{
	if (m_btnLowRight->IsEnabled())
	{
		board[2][2] = player;
		m_btnLowRight->Disable();

		if (player == 1)
		{
			m_btnLowRight->SetLabelText("x");
			player = 2;
		}
		else
		{
			if (player == 2)
			{
				m_btnLowRight->SetLabelText("o");
				player = 1;
			}
		}

		turnCounter++;
		victorious = checkBoard();

		if (victorious != 0 || turnCounter >= 9)
		{
			EndGame();
		}
	}
}

void cMain::OnBtnUpLeftEnterWindow(wxCommandEvent& event)
{
	if (m_btnUpLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnUpMiddleEnterWindow(wxCommandEvent& event)
{

	if (m_btnUpMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnUpRightEnterWindow(wxCommandEvent& event)
{
	if (m_btnUpRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleLeftEnterWindow(wxCommandEvent& event)
{
	if (m_btnMiddleLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleMiddleEnterWindow(wxCommandEvent& event)
{
	if (m_btnMiddleMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleRightEnterWindow(wxCommandEvent& event)
{
	if (m_btnMiddleRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowLeftEnterWindow(wxCommandEvent& event)
{
	if (m_btnLowLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowMiddleEnterWindow(wxCommandEvent& event)
{
	if (m_btnLowMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowRightEnterWindow(wxCommandEvent& event)
{
	if (m_btnLowRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnUpLeftLeaveWindow(wxCommandEvent& event)
{
	if (m_btnUpLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnUpMiddleLeaveWindow(wxCommandEvent& event)
{
	if (m_btnUpMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnUpRightLeaveWindow(wxCommandEvent& event)
{
	if (m_btnUpRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleLeftLeaveWindow(wxCommandEvent& event)
{
	if (m_btnMiddleLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleMiddleLeaveWindow(wxCommandEvent& event)
{
	if (m_btnMiddleMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnMiddleRightLeaveWindow(wxCommandEvent& event)
{
	if (m_btnMiddleRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowLeftLeaveWindow(wxCommandEvent& event)
{
	if (m_btnLowLeft->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowMiddleLeaveWindow(wxCommandEvent& event)
{
	if (m_btnLowMiddle->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}

void cMain::OnBtnLowRightLeaveWindow(wxCommandEvent& event)
{
	if (m_btnLowRight->IsEnabled())
	{
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a ");
		if (player == 1)
		{
			strcat(m_msgStatusBar, "x!");
		}
		else
		{
			if (player == 2)
			{
				strcat(m_msgStatusBar, "o!");
			}
		}
		SetStatusText(m_msgStatusBar);
	}
}