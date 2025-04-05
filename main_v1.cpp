#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

int main(int argc, char* argv[]) {
    // Initialize the Qt application
    QApplication app(argc, argv);

    // Create the main window
    QWidget window;
    window.setWindowTitle("Four Images Display");
    window.setFixedSize(640, 480);  // Set window size to 640x480

    // Create a grid layout
    QGridLayout* layout = new QGridLayout(&window);

    // Load four images into QPixmap objects
    QPixmap pix1("snorlax.jpg");  // Replace with your image paths
    QPixmap pix2("bulbasaur.jpg");
    QPixmap pix3("charmeleon.jpg");
    QPixmap pix4("cryogonal.jpg");

    // Create QLabel widgets to display the images
    QLabel* label1 = new QLabel();
    QLabel* label2 = new QLabel();
    QLabel* label3 = new QLabel();
    QLabel* label4 = new QLabel();

    // Scale images to fit (e.g., 300x220 each, leaving some margin)
    label1->setPixmap(pix1.scaled(300, 220, Qt::KeepAspectRatio));
    label2->setPixmap(pix2.scaled(300, 220, Qt::KeepAspectRatio));
    label3->setPixmap(pix3.scaled(300, 220, Qt::KeepAspectRatio));
    label4->setPixmap(pix4.scaled(300, 220, Qt::KeepAspectRatio));

    // Add labels to the grid layout (2x2 grid)
    layout->addWidget(label1, 0, 0);  // Top-left
    layout->addWidget(label2, 0, 1);  // Top-right
    layout->addWidget(label3, 1, 0);  // Bottom-left
    layout->addWidget(label4, 1, 1);  // Bottom-right

    // Set the layout for the window
    window.setLayout(layout);

    // Show the window
    window.show();

    // Run the application event loop
    return app.exec();
}
