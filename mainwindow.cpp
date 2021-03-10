#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_table_view = new QTableView(this);
    setCentralWidget(m_table_view);
    m_table_view->setAcceptDrops(false);
    setAcceptDrops(true);
    setWindowTitle("Examplate drag & drop");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "Drag event";
    if(event->mimeData()->hasFormat("text/uri-list")) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug() << "Drop event";

    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.empty()) {
        return;
    }

    QString filename = urls.first().toLocalFile();

    qDebug() << filename;

    qDebug() << m_counter.get()->checksum(filename);
}
