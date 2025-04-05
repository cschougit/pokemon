#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>

class ImageWindow : public QWidget {
    Q_OBJECT
private:
    QLabel* imageLabel;
    QPixmap pix1, pix2, pix3, pix4;

public:
    ImageWindow(QWidget* parent = nullptr) : QWidget(parent) {
        // Set up the window
        setWindowTitle("Image Switcher");
        setFixedSize(640, 480);

        // Load images
        pix1 = QPixmap("snorlax.jpg");  // Replace with your image paths
        pix2 = QPixmap("bulbasaur.jpg");
        pix3 = QPixmap("charmeleon.jpg");
        pix4 = QPixmap("cryogonal.jpg");

        // Create and configure the label
        imageLabel = new QLabel(this);
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setPixmap(pix1.scaled(100, 66, Qt::KeepAspectRatio));  // Initial image

        // Ensure the label fills the window
        imageLabel->setGeometry(0, 0, 640, 480);
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        switch (event->key()) {
        case Qt::Key_1:
        case Qt::Key_Left:
            imageLabel->setPixmap(pix1.scaled(100, 66, Qt::KeepAspectRatio));
            break;
        case Qt::Key_2:
        case Qt::Key_Right:
            imageLabel->setPixmap(pix2.scaled(100, 66, Qt::KeepAspectRatio));
            break;
        case Qt::Key_Up:
            imageLabel->setPixmap(pix3.scaled(100, 66, Qt::KeepAspectRatio));
            break;
        case Qt::Key_Down:
            imageLabel->setPixmap(pix4.scaled(100, 66, Qt::KeepAspectRatio));
            break;
        default:
            QWidget::keyPressEvent(event);  // Pass unhandled keys to parent
            return;
        }
        imageLabel->update();  // Refresh the display
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ImageWindow window;
    window.show();
    return app.exec();
}

#include "main.moc"  // Required for custom QObject subclass
