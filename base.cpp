#include "base.h"
#include "sortingfunctions.h"
#include<wx/grid.h>

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(ID_AddCR, MyFrame::OnAddCR)
EVT_BUTTON(ID_AddLA, MyFrame::OnAddLA)
EVT_BUTTON(ID_AddDR, MyFrame::OnAddDR)
EVT_BUTTON(ID_GenTableS, MyFrame::OnGenTableS)
EVT_BUTTON(ID_GenTableT, MyFrame::OnGenTableT)
EVT_BUTTON(ID_Quit, MyFrame::OnQuit)
END_EVENT_TABLE()

IMPLEMENT_APP(MyApp)



bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame("Routine Generator", wxDefaultPosition, wxDefaultSize);
	frame->Show(true);

	return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxPanel* panel = new wxPanel(this);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);

	

	AddCR = new wxButton(panel, ID_AddCR, "Add Class Requirements",wxDefaultPosition, wxSize(300,100));
	AddLA = new wxButton(panel, ID_AddLA, "Add Lecturers' Availability", wxDefaultPosition, wxSize(300, 100));
	AddDR = new wxButton(panel, ID_AddDR, "Add Department Requirements", wxDefaultPosition, wxSize(300, 100));
	

	hbox1->Add(AddCR);
	hbox1->Add(AddLA);
	hbox1->Add(AddDR);

	vbox->Add(1, 150);
	vbox->Add(hbox1, 0, wxCENTER);
	
	vbox->Add(1, 20);
	
	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
	
	GenTableS = new wxButton(panel, ID_GenTableS, "Generate Table (For Students)", wxDefaultPosition, wxSize(300, 100));
	GenTableT = new wxButton(panel, ID_GenTableT, "Generate Table (For Teachers)", wxDefaultPosition, wxSize(300, 100));
	
	hbox2->Add(GenTableS);
	hbox2->Add(GenTableT);
	
	vbox->Add(hbox2, 0, wxCENTRE);

	vbox->Add(1, 20);

	wxBoxSizer* hbox3 = new wxBoxSizer(wxHORIZONTAL);
	Quit = new wxButton(panel, ID_Quit, "Quit", wxDefaultPosition, wxSize(100, 100));

	hbox3->Add(Quit);


	vbox->Add(hbox3, 0, wxCENTRE);

	panel->SetSizer(vbox);
		
	Maximize();
	
}

TableFrame::TableFrame(const wxString& title1) :wxFrame(NULL, wxID_ANY, title1)
{
	int z = 0, k = 0;
	myclass c1;
	Depart d1;
	teach t1;
	c1.readfile(MyFrame::classpath.ToStdString());

	d1.readfile(MyFrame::departpath.ToStdString());

	t1.readfile(MyFrame::lecturerpath.ToStdString());

	findteacherswithlab(c1, d1, t1);

	find2lectureclass(c1, d1, t1);
	find1lectureclass(c1, d1, t1);

	wxGrid* grid = new wxGrid(this, wxID_ANY);
	grid->CreateGrid(6, 8);
	for(int i=0;i<6;i++)	grid->SetRowSize(i, 60);
	for(int i=0;i<8;i++)	grid->SetColSize(i, 120);

	for (int day = 0; day < 6; day++)
	{
		for (int period = 0; period < 8; period++)
		{
			grid->SetCellValue(day, period, c1.Timetable[day][period]);
		}
	}
	Maximize();
}






void MyFrame::OnAddCR(wxCommandEvent& event)
{
	
	wxFileDialog* OpenDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString,
		"Text file (*.txt)|*.txt", wxFD_OPEN);

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		classpath = OpenDialog->GetPath();
	}
}

void MyFrame::OnAddLA(wxCommandEvent& event)
{
	wxFileDialog* OpenDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString,
		"Text file (*.txt)|*.txt", wxFD_OPEN);

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		lecturerpath = OpenDialog->GetPath();
	}
}

void MyFrame::OnAddDR(wxCommandEvent& event)
{
	wxFileDialog* OpenDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString,
		"Text file (*.txt)|*.txt", wxFD_OPEN);

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		departpath = OpenDialog->GetPath();
	}
}

void MyFrame::OnGenTableS(wxCommandEvent& event)
{
	TableFrame* frame2 = new TableFrame("timetable");

	frame2->Show(true);
	
}

void MyFrame::OnGenTableT(wxCommandEvent& event)
{
	
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}

