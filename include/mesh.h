#ifndef _MESH_H_
#define _MESH_H_

#include "shape.h"
#include "objLoader.h"
#include "kdTree.h"
#include "util.h"
#include "geometry.h"

namespace rayTracer
{
//------------------------------------------------------------------------------
class Mesh : public Shape
{
public:
	Mesh ( const Vector& _pos, const std::string& _fileName, Material* _pMaterial = 0);
	~Mesh ();
	bool Intersect(const Ray& _ray, Intersection& o_intersection ) const;
	void ToCameraSpace( const Matrix& _transform );
	void SetMaterial( const Material* _pMaterial );

private:
	KdTree<Triangle> m_tree;
};//end of class
}//end of namespace
#endif
