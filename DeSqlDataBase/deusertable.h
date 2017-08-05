#ifndef DEUSERTABLE_H
#define DEUSERTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include <devalueobjectinterface.h>

///管理用户值对象
class DESQLDATABASE_EXPORT DeUserTable : public DeValueObjectInterface
{
public:
	enum UserPermission
	{
		ADMIN = 0,		//管理员
		MAINTAIN		//维护人员
	};

	DeUserTable(DeSqlDataBase *db);
	~DeUserTable();

	///初始化表结构
	void initTable();
	///验证用户是否已经存在
	bool isExist();
	///验证当前用户合法性
	bool isValid(); 
	///删除当前用户 userName-用户名
	bool delUser(const QString &userName);
	///设置用户名
	void setUserName(const QString &userName);
	///设置用户密码
	void setUserPasswd(const QString &userPasswd);
	///设置用户名权限名称
	void setUserPermissionName(const QString &permissionName);
	///设置用户权限
	void setUserPermission(DeUserTable::UserPermission permission);
	///获取用户名
	QString getUerName();
	///获取权限名称
	QString getUserPermissionName();
	///获取权限值
	int getUserPermission();

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	QString md5sum(const QString &passwd);

private:
	QString m_user;				  ///用户名
	QString m_passwd;			  ///密码
	QString m_userClassfy;		  ///用户权限名称
	int m_permission;			  ///用户权限
};

#endif // DEUSERTABLE_H
