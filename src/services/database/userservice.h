#ifndef USERSERVICE_H_
#define USERSERVICE_H_

#include <QObject>
#include <QSqlDatabase>
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QUuid>

class UserService : public QObject {
	Q_OBJECT

public:
	explicit UserService(QSqlDatabase *db, QObject *parent = 0);
	virtual ~UserService();
	enum AuthenticationResult {
		Success,
		NotFound,
		WrongPassword
	};
	enum RegistrationResult {
		Successful,
		Failed
	};

private:
	QSqlDatabase *db;

signals:
	void authenticationResult(AuthenticationResult);
	void registrationResult(RegistrationResult);

public slots:
	void registerNewUser(QString username, QString password);
	void authenticateUser(QString username, QString password);
};

#endif /* USERSERVICE_H_ */
