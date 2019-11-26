#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_TestCRSDll.h"
#include "CRS_SDK.h"
#include <QStringList>
#include <QFile>

#pragma execution_character_set("utf-8")

class TestCRSDll : public QMainWindow
{
	Q_OBJECT

public:
	TestCRSDll(QWidget *parent = Q_NULLPTR);

	static void onStatus_Callback(int e);

	static void onDAQ_Callback(int type, char* data);

	static void onTDC_Callback(int grp, int countC, int countF);

private:
	Ui::TestCRSDllClass ui;

	QStringList strList;

private:
	void initUI();
	void doIntegrationFunc(QString name);

	void onAWG();
	void onDDS();
	void onASG();
	void onDAQ();
	void onTDC();

private slots:
	void onAllPushButton();
};
