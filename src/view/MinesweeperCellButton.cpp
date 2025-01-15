#include "MinesweeperCellButton.hpp"

CellButton::CellButton(QWidget *parent, int row, int col, GameController *controller)
    : QPushButton(parent), row(row), col(col), viewController(controller)
{
}

void CellButton::mousePressEvent(QMouseEvent *event)
{
    if (viewController == nullptr)
    {
        std::cerr << "viewController is nullptr!" << std::endl;
        return;
    }

    if (event->button() == Qt::LeftButton)
    {
        if (viewController->LeftClickCell(row, col))
        {
            emit cellClicked(-1, -1);
        }
        else
        {
            emit cellClicked(row, col);
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        viewController->rightClickCell(row, col);
        emit cellClicked(row, col);
    }
}

void CellButton::setState(int newState)
{

    state = newState;
    update(); // Trigger repaint
}

void CellButton::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    if (state > 2)
    {
        // Fill background
        painter.fillRect(rect(), QColor("white"));
        if (state == 3)
        {
            return;
        }

        // Set text color based on number
        QString textColor;
        switch (state)
        {
        case 4: // 1
            textColor = "blue";
            break;
        case 5: // 2
            textColor = "green";
            break;
        case 6: // 3
            textColor = "red";
            break;
        default:
            textColor = "black";
        }

        // Draw the number
        painter.setPen(QColor(textColor));
        QFont font = painter.font();
        font.setPointSize(10); // Adjust size as needed
        painter.setFont(font);
        painter.drawText(rect(), Qt::AlignCenter, QString::number(state - 3));
        return;
    }
    else
    {
        // Get the pixmap for current state
        QString imagePath = getImageForState(state);
        QPixmap pixmap(imagePath);

        if (!pixmap.isNull())
        {
            // Scale the pixmap to fit the button while maintaining aspect ratio
            QPixmap scaled = pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

            // Calculate position to center the scaled pixmap
            int x = (width() - scaled.width()) / 2;
            int y = (height() - scaled.height()) / 2;
            // Draw the scaled image
            painter.drawPixmap(x, y, scaled);
        }
        else
        {
            // Draw error text with better visibility
            painter.fillRect(rect(), Qt::lightGray);
            painter.setPen(Qt::red);
            painter.drawText(rect(), Qt::AlignCenter, "Image Error!");
        }
    }
}

QString CellButton::getImageForState(int state) const
{
    // Use the :/ prefix to access resources
    switch (state)
    {
    case 0:
        return ":/assets/tile.jpg";
    case 1:
        return ":/assets/flagimage.jpg";
    case 2:
        return ":/assets/bombimage.jpg";
    default:
        return ":/assets/tile.jpg";
    }
}