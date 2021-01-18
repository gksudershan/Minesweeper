#include "main.h"

wxBEGIN_EVENT_TABLE(cmain, wxFrame)
wxEND_EVENT_TABLE()
cmain::cmain() : wxFrame(nullptr,wxID_ANY,"something",wxPoint(30,30),wxSize(800,600))
{
    btn = new wxButton*[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth,nFieldHeight,0,0);

    nField = new int[nFieldWidth * nFieldHeight];
    for(int x=0;x< nFieldWidth; x++)
    {
        for(int y=0; y< nFieldHeight; y++)
        {
            btn[y*nFieldWidth + x] = new wxButton(this, 10000 + (y* nFieldWidth + x));
            grid->Add(btn[y*nFieldWidth + x],1, wxEXPAND | wxALL);

            btn[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cmain::OnButtonClicked,this);
            nField[y*nFieldWidth + x] = 0;
        }
    }

    this->SetSizer(grid);
    grid->Layout();
}

cmain::~cmain()
{
    delete []btn;
}

void cmain::OnButtonClicked(wxCommandEvent &evt)
{
    
    int x = (evt.GetId()-10000) % nFieldWidth;
    int y = (evt.GetId()-10000) / nFieldWidth;

    if (bFirstClick)
    {
        int mines = 30;

        while (mines)
        {
            int rx = rand()%nFieldWidth;
            int ry = rand()%nFieldHeight;

            if (nField[ry*nFieldWidth + rx] == 0 && rx!=x && ry!=y)
            {
                nField[ry*nFieldWidth + rx]=-1;
                mines--;
            }
        }
        bFirstClick = false;
    }

    btn[y*nFieldWidth+x]->Enable(false);

    if (nField[y*nFieldWidth+x]==-1)
    {
        wxMessageBox("BOOOOOOOOM !! - Game Over :(");

        bFirstClick = true;
        for(int x=0;x< nFieldWidth; x++)
            for(int y=0; y< nFieldHeight; y++)
            {
                nField[y*nFieldWidth + x] = 0;
                btn[y*nFieldWidth+x]->SetLabel("");
                btn[y*nFieldWidth+x]->Enable(true);
            
            }
    
    }
    else
    {
        int mine_count = 0;
        for(int i=-1;i<2;i++)
            for(int j=-1;j<2;j++)
            {
                if(x+1>=0 && x+i<nFieldWidth && y+j>=0 && y+j<nFieldHeight)
                {
                    if(nField[(y+j)*nFieldWidth + (x+i)]==-1)
                        mine_count++;
                }
            }

        if (mine_count>0)
        {
            btn[y*nFieldWidth + x]-> SetLabel(std::to_string(mine_count));
        }

    }
    evt.Skip();
}