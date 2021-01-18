#include "app.h"
#include "main.h"
wxIMPLEMENT_APP(app);
app::app(){

}

app::~app(){

}

bool app::OnInit(){
    m_frame1 = new cmain;
    m_frame1->Show();
    return true;
}