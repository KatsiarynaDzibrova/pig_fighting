#include "gameobject.h"
#include "constants.h"
#include <vector>
#include <QDebug>
#include <QPixmap>

GameObject::GameObject(int x, int y, int height, int width)
    : position_{static_cast<double>(x), static_cast<double>(y)},
      bBox_{height, width} {
    qDebug() << "MAIN CONSTRUCTOR!";
}

void GameObject::Draw(QPainter& painter) const {
    /*painter.setRenderHint(QPainter::SmoothPixmapTransform);*/
    painter.drawRect(position_.x, position_.y,
                       bBox_.width_, bBox_.height_);
}

int GameObject::Width() const {
    return bBox_.width_;
}

int GameObject::Height() const {
    return bBox_.height_;
}

int GameObject::xPos() const {
    return position_.x;
}

int GameObject::yPos() const {
    return position_.y;
}

bool GameObject::Hits(const GameObject& obj) const {
    int max_y = std::max(yPos() + Height(), obj.yPos() + obj.Height());
    int min_y = std::min(yPos(), obj.yPos());
    int max_x = std::max(xPos() + Width(), obj.xPos() + obj.Width());
    int min_x = std::min(xPos(), obj.xPos());

    return (max_y - min_y <= Height() + obj.Height()) &&
           (max_x - min_x <= Width() + obj.Width());
}
