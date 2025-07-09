#pragma once

#include <QHeaderView>
#include <QPainter>

class CustomHeaderView : public QHeaderView {
public:
	CustomHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

protected:
	void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override;
};