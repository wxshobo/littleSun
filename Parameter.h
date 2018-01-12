#pragma once
#include <QString>

class Parameter
{
public:
	static Parameter* getInstance();
	QString m_vUserName;
	static Parameter *m_Parameter;

	void initParameter();
	Parameter();
	~Parameter();
};


