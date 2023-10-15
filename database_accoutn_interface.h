#pragma once

class database_account_interface
{
public:
	virtual ~database_account_interface() = default;
public:
	virtual void add_account() = 0 ;
	virtual void delete_account() = 0;
	virtual void find_account() = 0;
};