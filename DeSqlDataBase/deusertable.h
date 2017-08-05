#ifndef DEUSERTABLE_H
#define DEUSERTABLE_H

#include <QString>
#include "desqldatabase_global.h"
#include <devalueobjectinterface.h>

///�����û�ֵ����
class DESQLDATABASE_EXPORT DeUserTable : public DeValueObjectInterface
{
public:
	enum UserPermission
	{
		ADMIN = 0,		//����Ա
		MAINTAIN		//ά����Ա
	};

	DeUserTable(DeSqlDataBase *db);
	~DeUserTable();

	///��ʼ����ṹ
	void initTable();
	///��֤�û��Ƿ��Ѿ�����
	bool isExist();
	///��֤��ǰ�û��Ϸ���
	bool isValid(); 
	///ɾ����ǰ�û� userName-�û���
	bool delUser(const QString &userName);
	///�����û���
	void setUserName(const QString &userName);
	///�����û�����
	void setUserPasswd(const QString &userPasswd);
	///�����û���Ȩ������
	void setUserPermissionName(const QString &permissionName);
	///�����û�Ȩ��
	void setUserPermission(DeUserTable::UserPermission permission);
	///��ȡ�û���
	QString getUerName();
	///��ȡȨ������
	QString getUserPermissionName();
	///��ȡȨ��ֵ
	int getUserPermission();

protected:
	QString execAddString();
	QString execSelectString();
	QList<DeValueObjectInterface *> selectValue(QSqlQuery *sqlQuery);

private:
	QString md5sum(const QString &passwd);

private:
	QString m_user;				  ///�û���
	QString m_passwd;			  ///����
	QString m_userClassfy;		  ///�û�Ȩ������
	int m_permission;			  ///�û�Ȩ��
};

#endif // DEUSERTABLE_H
