#include "WCPRootVis/ViewGDS.h"
#include "WCPData/GeomWire.h"

using namespace WCPRootVis;
using namespace WCP;
using namespace std;

#include "TH1F.h"
#include "TLine.h"

ViewGDS::ViewGDS(const WCP::GeomDataSource& gds)
    : gds(gds)
{
}

ViewGDS::~ViewGDS()
{
}

void ViewGDS::draw(TPad& pad)
{
    pair<float,float> ybounds = gds.minmax(1);
    pair<float,float> zbounds = gds.minmax(2);

    TH1F* frame = pad.DrawFrame(zbounds.first, ybounds.first, 
				zbounds.second, ybounds.second);
    frame->SetXTitle("Z direction");
    frame->SetYTitle("Y direction");

    int colors[] = { 2,4,6 };

    for (int ind=0; ind<3; ++ind) {
	WirePlaneType_t planeid = static_cast<WirePlaneType_t>(ind);
	GeomWireSelection wires = gds.wires_in_plane(planeid);
	for (int iwire=0; iwire<wires.size(); ++iwire) {
	    const GeomWire* wire = wires[iwire];

	    Point p1=wire->point1();
	    Point p2=wire->point2();

	    TLine line(p1.z,p1.y, p2.z,p2.y);
	    line.SetLineColor(colors[ind]);
	    line.DrawClone();
	}
    }
}

void ViewGDS::update()
{
}

