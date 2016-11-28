#include "zChatterUI.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <string>


zChatterUI::zChatterUI( wxWindow* parent )
:
globalFrame( parent )
{
	zChatterUI::loadDefaults();
}

//DEFAULT USER DATA
void zChatterUI::loadDefaults(){
	zChatterUI::user_session_name = wxString{"Zmote89"};
	zChatterUI::user_session_host = wxString{"192.168.0.101"};
	zChatterUI::user_session_host_port = wxString{"9000"};
	zChatterUI::user_session_other_host = wxString{"89.102.10.20"};
	zChatterUI::user_session_other_host_post = wxString{"8000"};

	//Set input vars
	zChatterUI::session_name_input->SetValue(zChatterUI::user_session_name);
	zChatterUI::session_host_input->SetValue(zChatterUI::user_session_host);
	zChatterUI::session_host_port_input->SetValue(zChatterUI::user_session_host_port);
	zChatterUI::session_other_host_input->SetValue(zChatterUI::user_session_other_host);
	zChatterUI::session_other_host_port_input->SetValue(zChatterUI::user_session_other_host_post);

	//Set record vars
	zChatterUI::cs_s_name_info->SetLabel(zChatterUI::session_name_input->GetValue());
	zChatterUI::cs_host_ip_port_info->SetLabel(zChatterUI::session_host_input->GetValue()
			+ ":" + zChatterUI::session_host_port_input->GetValue());
	zChatterUI::cs_other_host_ip_port_info->SetLabel(zChatterUI::session_other_host_input->GetValue()
			+ ":" + zChatterUI::session_other_host_port_input->GetValue());
}

//EVENT HANDLER BUTTONS
void zChatterUI::handle_connect( wxCommandEvent& event )
{
	//TODO: Socket logik, connect
}
void zChatterUI::handle_disconnect( wxCommandEvent& event )
{
	//TODO: Socket logik, disconnect
}
void zChatterUI::handle_save_settings( wxCommandEvent& event )
{
	//Set labels
	zChatterUI::cs_s_name_info->SetLabel(zChatterUI::session_name_input->GetValue());
	zChatterUI::cs_host_ip_port_info->SetLabel(zChatterUI::session_host_input->GetValue()
			+ ":" + zChatterUI::session_host_port_input->GetValue());
	zChatterUI::cs_other_host_ip_port_info->SetLabel(zChatterUI::session_other_host_input->GetValue()
			+ ":" + zChatterUI::session_other_host_port_input->GetValue());

	//Set vars
	zChatterUI::user_session_name = zChatterUI::session_name_input->GetValue();
	zChatterUI::user_session_host = zChatterUI::session_host_input->GetValue();
	zChatterUI::user_session_host_port = zChatterUI::session_host_port_input->GetValue();
	zChatterUI::user_session_other_host = zChatterUI::session_other_host_input->GetValue();
	zChatterUI::user_session_other_host_post = zChatterUI::session_other_host_port_input->GetValue();
}

void zChatterUI::handle_send(wxCommandEvent & event)
{
	zChatterUI::handle_chat_text_input(event);
}

//EVENT HANDLER FIELDS
void zChatterUI::handle_session_name_input( wxCommandEvent& event )
{
	zChatterUI::set_session_name(event.GetString());
}
void zChatterUI::handle_host_input( wxCommandEvent& event )
{
	zChatterUI::set_session_host(event.GetString());
}
void zChatterUI::handle_host_port_input( wxCommandEvent& event )
{
	zChatterUI::set_session_host_port(event.GetString());
}
void zChatterUI::handle_other_host_input( wxCommandEvent& event )
{
	zChatterUI::set_session_other_host(event.GetString());
}
void zChatterUI::handle_other_host_port( wxCommandEvent& event )
{
	zChatterUI::set_session_other_host_port(event.GetString());
}
void zChatterUI::handle_chat_text_input( wxCommandEvent& event )
{
	wxString chat_input{zChatterUI::chat_text_input->GetValue()};
	if(!chat_input.empty()){
		wxString prepend{"[" + zChatterUI::get_session_name() + "]: "};
		zChatterUI::chat_text_output->SetValue(zChatterUI::chat_text_output->GetValue() + "\n" + prepend + zChatterUI::chat_text_input->GetValue());
		zChatterUI::chat_text_input->SetValue("");
	}
}

//DATA MANIPULATORS
void zChatterUI::set_session_name(wxString name)
{
	zChatterUI::user_session_name = name;
}
wxString zChatterUI::get_session_name()
{
	return zChatterUI::user_session_name;
}

void zChatterUI::set_session_host(wxString name)
{
	zChatterUI::user_session_host = name;
}
wxString zChatterUI::get_session_host()
{
	return zChatterUI::user_session_host;
}

void zChatterUI::set_session_host_port(wxString name)
{
	zChatterUI::user_session_host_port = name;
}
wxString zChatterUI::get_session_host_port()
{
	return zChatterUI::user_session_host_port;
}

void zChatterUI::set_session_other_host(wxString name)
{
	zChatterUI::user_session_other_host = name;
}
wxString zChatterUI::get_session_other_host()
{
	return zChatterUI::user_session_other_host;
}

void zChatterUI::set_session_other_host_port(wxString name)
{
	zChatterUI::user_session_other_host_post = name;
}
wxString zChatterUI::get_session_other_host_port()
{
	return zChatterUI::user_session_other_host_post;
}
