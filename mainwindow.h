#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QTableView>


#include "checksum_counter.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private:
    // Methods
    void drop_event(QDropEvent* event);

    // Members
    Ui::MainWindow *ui;

    QTableView* m_table_view;

    std::unique_ptr<ChecksumCounter> m_counter{std::make_unique<ChecksumCounter>()};
};
#endif // MAINWINDOW_H
