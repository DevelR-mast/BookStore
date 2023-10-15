#pragma once
#include <iostream>
#include <vector>
#include "account_interface.h"
#include "database_accoutn_interface.h"

class database_account: public database_account_interface
{
private:
	std::vector<account_base*> container_account;
public:
	database_account() = default;
	~database_account() = default;
public:
	void add_account() override;
	void delete_account() override;
	void find_account() override;
};

