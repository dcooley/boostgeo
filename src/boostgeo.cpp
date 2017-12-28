// [[Rcpp::depends(BH)]]

#include <Rcpp.h>
using namespace Rcpp;

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/polygon.hpp>

namespace geom = boost::geometry;

// READING WKT

// [[Rcpp::export]]
void wktTest() {

  typedef boost::geometry::model::d2::point_xy<double> point_type;

  point_type a;
  boost::geometry::model::linestring<point_type> b;
  boost::geometry::model::polygon<point_type> c;
  boost::geometry::model::box<point_type> d;
  boost::geometry::model::segment<point_type> e;

  boost::geometry::read_wkt("POINT(1 2)", a);
  boost::geometry::read_wkt("LINESTRING(0 0,2 2,3 1)", b);
  boost::geometry::read_wkt("POLYGON((0 0,0 7,4 2,2 0,0 0))", c);
  boost::geometry::read_wkt("BOX(0 0,3 3)", d);
  boost::geometry::read_wkt("SEGMENT(1 0,3 4)", e);

  //Rcpp::Rcout << a << std::endl;

  point_type point = geom::make<point_type>(3, 6);
  geom::model::polygon<point_type> polygon;
  geom::append(geom::exterior_ring(polygon), geom::make<point_type>(0, 0));
  geom::append(geom::exterior_ring(polygon), geom::make<point_type>(0, 4));
  geom::append(geom::exterior_ring(polygon), geom::make<point_type>(4, 4));
  geom::append(geom::exterior_ring(polygon), geom::make<point_type>(4, 0));
  geom::append(geom::exterior_ring(polygon), geom::make<point_type>(0, 0));

  std::cout << boost::geometry::wkt(point) << std::endl;
  std::cout << boost::geometry::wkt(polygon) << std::endl;



}



