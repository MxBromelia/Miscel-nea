import sys
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QWidget, QLabel, QLineEdit, 
    QTableWidget, QVBoxLayout, QHBoxLayout,
    QTextEdit, QScrollArea, QApplication)

class DinQTableWidget(QTableWidget):
    def __init__(self, rows, cols, parent):
        super(QTableWidget,self).__init__(rows, cols, parent)
    
    def keyPressEvent(self, key):
        if (key.key() == Qt.Key_Enter or key.key() == Qt.Key_Return):
            if self.currentRow() == self.rowCount()-1:
                self.insertRow(self.rowCount())

class Form(QWidget):
    def __init__(self):
        super().__init__()

        self.initUI()
    
    def initUI(self):
        qvb = QVBoxLayout()

        pkl = QLabel('PACKING LIST')
        pkl.setAlignment(Qt.AlignCenter)

        tw = DinQTableWidget(1,7, self)
        clabels = ['ITEM NR', 'QTY', 'UNIT', 'GOODS DESCRIPTION',
                   'NET WEIGHT', 'GROSS WEIGHT', 'CUBIC METER']
        tw.setHorizontalHeaderLabels(clabels)
        for i in range(0,tw.columnCount()):
            tw.setColumnWidth(i,len(clabels[i])*10)
        tw.resize(tw.sizeHint())

        qvb.addWidget(pkl)
        qvb.addWidget(tw)
        qvb.addWidget(QLabel('MARKS:'))
        qvb.addWidget(QTextEdit())

        self.setLayout(qvb)
        self.setGeometry(300,300,679,600)
        self.setWindowTitle('Review')
        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Form()
    sys.exit(app.exec_())