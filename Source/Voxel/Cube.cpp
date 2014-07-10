#include "Voxel.h"
#include "Cube.h"


ACube::ACube(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{

	Mesh = PCIP.CreateDefaultSubobject<UGeneratedMeshComponent>(this, TEXT("GeneratedMesh"));

	RootComponent = Mesh;
}

void ACube::SetBox(const float& Size, const FVector& Position)
{
	TArray<FGeneratedMeshTriangle> triangles;

	// make vertex positions
	FVector p0 = FVector(Position.X, Position.Y, Position.Z);
	FVector p1 = FVector(Position.X, Position.Y, Position.Z + Size);
	FVector p2 = FVector(Position.X + Size, Position.Y, Position.Z + Size);
	FVector p3 = FVector(Position.X + Size, Position.Y, Position.Z);
	FVector p4 = FVector(Position.X + Size, Position.Y + Size, Position.Z);
	FVector p5 = FVector(Position.X + Size, Position.Y + Size, Position.Z + Size);
	FVector p6 = FVector(Position.X, Position.Y + Size, Position.Z + Size);
	FVector p7 = FVector(Position.X, Position.Y + Size, Position.Z);

	FGeneratedTriangleVertex v0;
	FGeneratedTriangleVertex v1;
	FGeneratedTriangleVertex v2;
	FGeneratedTriangleVertex v3;
	v0.U = 0; v0.V = 0;
	v1.U = 0; v1.V = .5;
	v2.U = .5; v2.V = .5;
	v3.U = .5; v3.V = 0;

	FGeneratedMeshTriangle t1;
	FGeneratedMeshTriangle t2;

	// front face
	v0.Position = p0;
	v1.Position = p1;
	v2.Position = p2;
	v3.Position = p3;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	//back face
	v0.Position = p4;
	v1.Position = p5;
	v2.Position = p6;
	v3.Position = p7;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// left face
	v0.Position = p7;
	v1.Position = p6;
	v2.Position = p1;
	v3.Position = p0;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// right face
	v0.Position = p3;
	v1.Position = p2;
	v2.Position = p5;
	v3.Position = p4;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// top face
	v0.Position = p1;
	v1.Position = p6;
	v2.Position = p5;
	v3.Position = p2;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	// bottom face
	v0.Position = p3;
	v1.Position = p4;
	v2.Position = p7;
	v3.Position = p0;
	t1.Vertex0 = v0;
	t1.Vertex1 = v1;
	t1.Vertex2 = v2;
	t2.Vertex0 = v0;
	t2.Vertex1 = v2;
	t2.Vertex2 = v3;
	triangles.Add(t1);
	triangles.Add(t2);

	Mesh->SetGeneratedMeshTriangles(triangles);
}