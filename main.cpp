#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>

class ImageGridWindow : public QWidget {
    Q_OBJECT
private:
    QLabel* imageLabel;           // Single label for the image
    QGridLayout* gridLayout;      // 6x6 grid layout
    QPixmap pix1, pix2, pix3, pix4;  // Image pixmaps
    int currentRow, currentCol;   // Current position of the image

public:
    ImageGridWindow(QWidget* parent = nullptr) : QWidget(parent), currentRow(-1), currentCol(-1) {
        // Set up the window
        setWindowTitle("Image Grid Mover");
        setFixedSize(640, 480);

        // Create the 6x6 grid layout
        gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(0);  // No spacing between cells
        gridLayout->setContentsMargins(0, 0, 0, 0);  // No margins

        // Initialize empty grid with transparent labels
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 6; ++col) {
                QLabel* emptyLabel = new QLabel(this);
                emptyLabel->setFixedSize(640 / 6, 480 / 6);  // Each cell: 106x80
                gridLayout->addWidget(emptyLabel, row, col);
            }
        }

        // Load images
        pix1 = QPixmap("snorlax.jpg");  // Replace with your image paths
        pix2 = QPixmap("bulbasaur.jpg");
        pix3 = QPixmap("charmeleon.jpg");
        pix4 = QPixmap("pikachu.jpg");

        // Create the image label (initially not placed)
        imageLabel = new QLabel(this);
        imageLabel->setFixedSize(640 / 6, 480 / 6);  // Match grid cell size
        imageLabel->setAlignment(Qt::AlignCenter);
    }

protected:
    void keyPressEvent(QKeyEvent* event) override {
        // Handle number keys to display images at (0,0) if no image is present
        if (currentRow == -1 && currentCol == -1) {
            switch (event->key()) {
            case Qt::Key_1:
                imageLabel->setPixmap(pix1.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                placeImage(0, 0);
                break;
            case Qt::Key_2:
                imageLabel->setPixmap(pix2.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                placeImage(0, 0);
                break;
            case Qt::Key_3:
                imageLabel->setPixmap(pix3.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                placeImage(0, 0);
                break;
            case Qt::Key_4:
                imageLabel->setPixmap(pix4.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                placeImage(0, 0);
                break;
            default:
                QWidget::keyPressEvent(event);
                return;
            }
        }
        else {
            // Handle arrow keys to move the image
            int newRow = currentRow;
            int newCol = currentCol;
            switch (event->key()) {
            case Qt::Key_Left:
                if (currentCol > 0) newCol--;
                break;
            case Qt::Key_Right:
                if (currentCol < 5) newCol++;
                break;
            case Qt::Key_Up:
                if (currentRow > 0) newRow--;
                break;
            case Qt::Key_Down:
                if (currentRow < 5) newRow++;
                break;
            case Qt::Key_1:
                imageLabel->setPixmap(pix1.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                break;
            case Qt::Key_2:
                imageLabel->setPixmap(pix2.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                break;
            case Qt::Key_3:
                imageLabel->setPixmap(pix3.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                break;
            case Qt::Key_4:
                imageLabel->setPixmap(pix4.scaled(640 / 6, 480 / 6, Qt::KeepAspectRatio));
                break;
            default:
                QWidget::keyPressEvent(event);
                return;
            }
            if (newRow != currentRow || newCol != currentCol) {
                placeImage(newRow, newCol);
            }
        }
        update();  // Refresh the display
    }

private:
    void placeImage(int row, int col) {
        // Remove the image from its current position (if any)
        if (currentRow != -1 && currentCol != -1) {
            gridLayout->removeWidget(imageLabel);
        }
        // Place the image at the new position
        gridLayout->addWidget(imageLabel, row, col);
        currentRow = row;
        currentCol = col;
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ImageGridWindow window;
    window.show();
    return app.exec();
}

#include "main.moc"  // Required for Q_OBJECT