#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "zChatterUI.h"
#include "zChatterUI.cpp"
#include "chat_ui.cpp"

void testDefaultsLoadedForSessionHost() {
	zChatterUI zcui{NULL};
	zcui.loadDefaults();
	ASSERT(!zcui.get_session_host().IsEmpty());
}

void testDefaultsLoadedForSessionHostPort() {
	zChatterUI zcui{NULL};
	zcui.loadDefaults();
	ASSERT(!zcui.get_session_host_port().IsEmpty());
}

void testDefaultsLoadedForSessionName() {
	zChatterUI zcui{NULL};
	zcui.loadDefaults();
	ASSERT(!zcui.get_session_name().IsEmpty());
}

void testDefaultsLoadedForSessionOtherHost() {
	zChatterUI zcui{NULL};
	zcui.loadDefaults();
	ASSERT(!zcui.get_session_other_host().IsEmpty());
}

void testDefaultsLoadedForSessionOtherHostPort() {
	zChatterUI zcui{NULL};
	zcui.loadDefaults();
	ASSERT(!zcui.get_session_other_host_port().IsEmpty());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	s.push_back(CUTE(testDefaultsLoadedForSessionHost));
	s.push_back(CUTE(testDefaultsLoadedForSessionHostPort));
	s.push_back(CUTE(testDefaultsLoadedForSessionName));
	s.push_back(CUTE(testDefaultsLoadedForSessionOtherHost));
	s.push_back(CUTE(testDefaultsLoadedForSessionOtherHostPort));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner { cute::makeRunner(lis, argc, argv) };
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
