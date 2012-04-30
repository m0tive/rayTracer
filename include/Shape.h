#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "vector.h"
#include "material.h"

namespace rayTracer
{
class Shape
{
public:
    Shape()
    : m_pMaterial (0)
    {}
    ~Shape();
    
    const Vector& Position () const { return m_position; };
    void SetMaterial ( const Material* _material) { m_pMaterial = _material; };
    const Material* GetMaterial () const { return m_pMaterial; };
    virtual bool Intersect ( const Ray& _ray, Intersection& o_intersection ) const = 0;

private:
    Vector m_position;
    const Material* m_pMaterial;
    Vector m_u;
    Vector m_v;
};//end of class
}//end of namespace
#endif //end of define
