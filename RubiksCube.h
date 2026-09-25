#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include <iostream>
#include <fstream>
#include <string>

class RubiksCube {
private:
	// динамический массив для хранения 54 цветов
	int* colors;

	static const int SIZE = 54;
	static const int FACE_SIZE = 9;

	void rotateFaceData(int faceindex, bool clockwise);
	void shiftEdgesCycle(const int* p1, const int* p2, const int* p3, const int* p4, bool clockwise);
	void rotateEdges(int faceindex, bool clockwise);

public:
	// конструкторы, деструкторы, оепраторы присваивания
	RubiksCube();
	RubiksCube(const RubiksCube& other);
	RubiksCube& operator=(const RubiksCube& other);
	~RubiksCube();
	//основные методы управления кубиком
	void scramble(int moves = 20); //перемешать
	void rotateFace(int faceindex, bool clockwise);//повернуть сторону
	bool isSolved() const;//собран ли
	int getColor(int index) const;//получить цвет
	bool loadFromFile(const std::string& filename);//загрузить из файла
	//Операторы сравнения
	bool operator==(const RubiksCube& other) const;
	bool operator!=(const RubiksCube& other) const;
	//потоковые операторы
	friend std::ostream& operator<<(std::ostream& os, const RubiksCube& cube);
	friend std::ifstream& operator>>(std::ifstream& is, RubiksCube& cube);
};

#endif