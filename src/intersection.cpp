#include "intersection.h"
namespace rayTracer
{
//------------------------------------------------------------------------------
Intersection::Intersection()
: m_rayParameter( FLT_MAX ),
  m_pMaterial(0)
{}
//------------------------------------------------------------------------------
Intersection::Intersection( const Vector& _position,
                             const Vector& _normal,
                             const Vector2D& _texCoord,
                             float _rayParameter,
                             const Material* _pMaterial )
: m_position( _position ),
  m_normal( _normal ),
  m_texCoord( _texCoord ),
  m_rayParameter( _rayParameter ),
  m_pMaterial( _pMaterial )
{}
//------------------------------------------------------------------------------
Intersection::Intersection( const Intersection& _other )
: m_position( _other.m_position ),
  m_normal( _other.m_normal ),
  m_texCoord( _other.m_texCoord ),
  m_rayParameter( _other.m_rayParameter ),
  m_pMaterial( _other.m_pMaterial )
{}
//------------------------------------------------------------------------------
Intersection& Intersection::operator = (const Intersection& _other)
{
    m_position = _other.m_position;
    m_normal = _other.m_normal;
    m_texCoord = _other.m_texCoord;
    m_rayParameter = _other.m_rayParameter;
    m_pMaterial = _other.m_pMaterial;
    return *this;
}
}//end of namespace
