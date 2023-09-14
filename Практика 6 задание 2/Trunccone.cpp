#include <iostream>
#include <cmath>
#include <locale>
#include <windows.h>
#include "Trunccone.h"
using namespace std;
    Trunccone::Trunccone() {
        x = y = z = h = r = 0;
    }
    Trunccone::Trunccone(double r, double h, double radius, double height) :Cone(radius, height) {
        this->h = h;
        this->r = r;
        this->radius = radius;
        this->height = height;
        x = 0;
        y = 0;
        z = 0;

    }
    Trunccone::Trunccone(double x, double y, double z, double r, double h, double radius, double height) :Cone(radius, height) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->h = h;
        this->r = r;
        this->radius = radius;
        this->height = height;
    }
    void Trunccone::setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
    void Trunccone::setHeight(double h) { height = h; }
    void Trunccone::setR(double r) { this->r = r; }
    double Trunccone::getH() { return h; }
    double Trunccone::getHeight() { return height; }
    double Trunccone::getR() { return r; }
    double Trunccone::getRadius() { return radius; }
    double Trunccone::getX() { return x; }
    double Trunccone::getY() { return y; }
    double Trunccone::getZ() { return z; }
    double Trunccone::area() {
        double a = radius - r;
        double l = sqrt(h * h + a * a);
        return pi * l * (radius + r) + pi * pow(radius, 2) + pi * pow(r, 2);
    }
    double Trunccone::volume() {
        return Cone::volume() - (pi * r * r * h / 3);
    }
    void Trunccone::show() {
        if (x != 0 && y != 0 && z != 0) {
            cout << "���������� ���������� ������: (" << x << "," << y << "," << z << ")" << endl;
        }
        cout << "������� ������ ����������� ���������� ������: " << area() << endl;
        cout << "����� ���������� ������: " << volume() << endl;

    }
    void Trunccone::comparison(Trunccone& obj1, Trunccone& obj2) {//���������
        if (obj1.area() > obj2.area()) {
            cout << "������� ������ � �.�������� = " << obj1.getRadius() << ", " << "�.�������� = " << obj1.getR() << " � ������� = " << abs(obj1.getHeight() - obj1.getH()) << " ������, ��� " << "������� ������ � �.�������� = " << obj2.getRadius() << ", " << "�.�������� = " << obj2.getR() << " � ������� = " << abs(obj2.getHeight() - obj2.getH()) << endl;
        }
        else if (obj1.area() < obj2.area()) {
            cout << "������� ������ � �.�������� = " << obj2.getRadius() << ", " << "�.�������� = " << obj2.getR() << " � ������� = " << abs(obj2.getHeight() - obj2.getH()) << " ������, ��� " << "������� ������ � �.�������� = " << obj1.getRadius() << ", " << "�.�������� = " << obj1.getR() << " � ������� = " << abs(obj1.getHeight() - obj1.getH()) << endl;
        }
        else {
            cout << "������� ������" << endl;
        }
        if (obj1.volume() > obj2.volume()) {
            cout << "����� ������ � �.�������� = " << obj1.getRadius() << ", " << "�.�������� = " << obj1.getR() << " � ������� = " << abs(obj1.getHeight() - obj1.getH()) << " ������, ��� " << "������� ������ � �.�������� = " << obj2.getRadius() << ", " << "�.�������� = " << obj2.getR() << " � ������� = " << abs(obj2.getHeight() - obj2.getH()) << endl;
        }
        else if (obj1.volume() < obj2.volume()) {
            cout << "����� ������ � �.�������� = " << obj2.getRadius() << ", " << "�.�������� = " << obj2.getR() << " � ������� = " << abs(obj2.getHeight() - obj2.getH()) << " ������, ��� " << "������� ������ � �.�������� = " << obj1.getRadius() << ", " << "�.�������� = " << obj1.getR() << " � ������� = " << abs(obj1.getHeight() - obj1.getH()) << endl;
        }
        else {
            cout << "������ ������" << endl;
        }
    }
    ostream& operator<<(ostream& stream, Trunccone obj) {
        return
         stream << "(" << obj.getX() << "; " << obj.getY() << "; " << obj.getX() << ") " << "\n";
    }
