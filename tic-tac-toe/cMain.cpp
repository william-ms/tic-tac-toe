#include "cMain.h"

enum
{
	ID_NewGame = 1,
	ID_Button = 10000
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


	//Adicionar grade do jogo
	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	gBoard = new wxGridSizer(3, 3, 0, 0);
	gBoard->SetMinSize(500, 500);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_buttons[i][j] = new wxButton(this, i * 10000 + j, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
			m_buttons[i][j]->SetFont(font);
			m_buttons[i][j]->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnBtnClick), NULL, this);
			m_buttons[i][j]->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(cMain::OnBtnEnterWindow), NULL, this);
			gBoard->Add(m_buttons[i][j], 0, wxALL | wxEXPAND, 5);
		}
	}

	this->SetSizer(gBoard);
	this->Layout();

	//Adicionar barra de status
	m_statusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	DisableGrid();
	SetStatusText("Go to New Game to start a match");

	Bind(wxEVT_MENU, &cMain::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &cMain::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &cMain::OnAbout, this, wxID_ABOUT);
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

void cMain::OnBtnClick(wxCommandEvent& event)
{
	idCurrent = event.GetId();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			idBtn = m_buttons[i][j]->GetId();
			if (idCurrent == idBtn && m_buttons[i][j]->IsEnabled())
			{
				board[i][j] = player;
				m_buttons[i][j]->Disable();

				if (player == 1)
				{
					m_buttons[i][j]->SetLabelText("X");
					player = 2;
				}
				else
				{
					if (player == 2)
					{
						m_buttons[i][j]->SetLabelText("O");
						player = 1;
					}
				}
			}
		}
	}

	turnCounter++;
	victorius = checkBoard();

	if (victorius != 0 || turnCounter >= 9)
	{
		EndGame();
	}
}

void cMain::OnBtnEnterWindow(wxCommandEvent& event)
{
	idCurrent = event.GetId();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			idBtn = m_buttons[i][j]->GetId();
			if (idCurrent == idBtn && m_buttons[i][j]->IsEnabled())
			{
				strcpy(m_msgStatusBar, "");
				strcpy(m_msgStatusBar, "Click here to mark a ");

				if (player == 1)
				{
					strcat(m_msgStatusBar, "X!");
				}
				else
				{
					if (player == 2)
					{
						strcat(m_msgStatusBar, "O!");
					}
				}
			}

			SetStatusText(m_msgStatusBar);
		}
	}

}

void cMain::EnableGrid()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_buttons[i][j]->Enable();
			m_buttons[i][j]->SetLabelText("");
		}
	}
}

void cMain::DisableGrid()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_buttons[i][j]->Disable();
			m_buttons[i][j]->SetLabelText("");
		}
	}
}

void cMain::EndGame()
{
	char mensagem[200] = "";

	if (victorius == 0)
	{
		strcpy(mensagem, "TIED MATCH!");
	}
	else
	{
		if (victorius == 1)
		{
			strcpy(mensagem, "X - Player 1 wins!");
		}
		else
		{
			if (victorius == 2)
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
	victorius = 0;

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