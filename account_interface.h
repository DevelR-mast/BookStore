#pragma once

class account_base
{
public:
	virtual ~account_base() = default;
public:
	virtual void set_login() = 0;
	virtual void set_password() = 0;
	virtual void set_name() = 0;
	virtual void set_family() = 0;
	virtual void set_phonenumber() = 0;
};