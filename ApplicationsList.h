#pragma once

class ApplicationsList
{
public:
	void createApplication();
	void getApplication(); // + peregruzka po ID
	void updateApplication(int);
	void deleteApplication(int);
	void printApplications();
	void sortApplications();
	void filterApplications(); // peregruzka po condition int/str...
};