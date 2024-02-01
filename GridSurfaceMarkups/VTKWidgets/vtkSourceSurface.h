#ifndef GENERIC_SURFACE_SOURCE_H
#define GENERIC_SURFACE_SOURCE_H

#include "vtkBezierSurfaceSource.h"
#include "vtkNURBSSurfaceSource.h"
#include "vtkPolyDataAlgorithm.h"
#include "vtkSmartPointer.h"
#include "vtkPoints.h"

class vtkSourceSurface{
public:
    // Enum to represent the type of surface source
    enum SurfaceType { Bezier, Nurbs, Custom };

    // Constructor and Destructor
    vtkSourceSurface();
    ~vtkSourceSurface();

    // Methods to set the surface source
    void SetBezier(vtkBezierSurfaceSource* source);
    void SetNurbs(vtkNURBSSurfaceSource* source);
    void SetCustom(vtkPolyDataAlgorithm* source);

    // Method to perform action based on the current type
    void PerformActionBasedOnType(vtkPoints* points);

private:
    // Current type of the surface source
    SurfaceType currentType;

    // Smart pointer to the current surface source
    vtkSmartPointer<vtkPolyDataAlgorithm> currentSource;

    // Preventing copying and assignment
    vtkSourceSurface(const vtkSourceSurface&) = delete;
    vtkSourceSurface& operator=(const vtkSourceSurface&) = delete;
};

#endif // GENERIC_SURFACE_SOURCE_H



