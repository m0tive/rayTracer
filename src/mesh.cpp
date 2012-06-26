#include "mesh.h"
#include "float.h"
namespace rayTracer
{
//------------------------------------------------------------------------------
Mesh::~Mesh ()
{}
//------------------------------------------------------------------------------
Mesh::Mesh ( const Vector& _pos, const ObjLoader& _obj, Material* _pMaterial )
: m_tree(5)
{
	Translate(_pos);
	m_pMaterial = _pMaterial;

	uint32_t size = _obj.GetVertexArray().size();
	m_tree.m_data.reserve(size);
	for(uint32_t i=0; i< size; i+=3 )
	{
		m_tree.m_data.push_back( Triangle( _obj.GetVertexArray()[i], _obj.GetVertexArray()[i+1], _obj.GetVertexArray()[i+2],
								  _obj.GetNormalArray()[i], _obj.GetNormalArray()[i+1], _obj.GetNormalArray()[i+2] , i/3.0) );
	}
	m_tree.SetBBox();
}
//------------------------------------------------------------------------------
void Mesh::ToCameraSpace( const Matrix& _transform)
{
	m_tree.Transform( _transform );
	uint32_t depth=0;
	m_tree.BuildTree( m_tree.m_root, depth );
	//std::cout<<Position()<<"\n";
}
//------------------------------------------------------------------------------
void Mesh::PrintData () const
{
#if 0
	for ( uint32_t i=0;i< m_pointArray.size ( ); ++i )
	{
		Vector t = m_pointArray[i];
	}
	for ( uint32_t i=0 ;i< m_normalArray.size ( ); ++i )
	{
		Vector t = m_normalArray[i];
	}
#endif
}
//------------------------------------------------------------------------------
bool Mesh::Intersect ( const Ray& _ray, Intersection& o_intersection ) const
{
	//intersect kd tree
	bool result = m_tree.Intersect( m_tree.m_root, _ray, o_intersection );
	if(result )
	{
		o_intersection.SetMaterial( m_pMaterial );
	}
	return result;
	
	//set material
#if 0
	if (  m_pointArray.size () != 0 && m_normalArray.size () !=0 )
	{
		
		float parameter = FLT_MAX;
		for ( uint32_t i=0; i< m_pointArray.size () ;i+=3 )
		{
			RayTriangle ( _ray, m_transform * m_pointArray[i], m_transform * m_pointArray[i+1], m_transform * m_pointArray[i+2], _intersection, parameter );
		}
		return (  _intersection.RayParameter () < FLT_MAX );
	}
	else
		return false;
#endif
}
//------------------------------------------------------------------------------
void Mesh::ToUVSpace( const Vector& _pos, float& o_u, float& o_v ) const
{

}
}//end of namespace
