#pragma once

#include <QAbstractTableModel>
#include <QString>
#include <QVariant>
#include <QPushButton>

class CustomTableModel : public QAbstractTableModel {
	Q_OBJECT
public:
	CustomTableModel(QObject* parent = nullptr);
	~CustomTableModel() = default;

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};