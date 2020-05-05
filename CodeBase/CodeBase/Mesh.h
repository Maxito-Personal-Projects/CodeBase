#ifndef __MESH_H__
#define __MESH_H__

#include <string>
#include <map>

class GameObject;

class Mesh
{
public:

	Mesh(GameObject* _parent, int x, int y);
	~Mesh();

	void DrawMesh();
	void GenerateFlatMesh_quads(int x, int y);
	void LoadToGPU();
	void FillInfoGPU();

	void GenerateVertexBuffer();

public:

	float* vertices = nullptr;
	int* testIndices = nullptr;
	int* tileCoords = nullptr;

	//float* faceNormals = nullptr;
	float* infoGPU = nullptr;

	int numVertices = 8;
	int numIndices = 36;

	uint VBO;	//Vertex Buffer Object
	uint VAO;	//Vertex Array Object
	uint IBO;	//Index Buffer Object
	uint TBO;	//Transform Feedback Buffer Object

	float* vertexBuffer = nullptr;
	int buffSize = 0;

	GameObject* parent = nullptr;

	int size = 2;
	float width = 64.0f;
	float height = 64.0f;
	float divisions = 64.0f;

	int chunkX = 0;
	int chunkY = 0;

	float time = 0.0f;

};

#endif //!__MESH_H__