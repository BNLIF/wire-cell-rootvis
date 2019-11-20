#ifndef WIRECELLROOTVIS_VIEWGDS
#define  WIRECELLROOTVIS_VIEWGDS

#include "WCPRootVis/ViewMixin.h"
#include "WCPNav/GeomDataSource.h"

namespace WCPRootVis {

    class ViewGDS : public ViewMixin
    {
	const WCP::GeomDataSource& gds;
    public:
	ViewGDS(const WCP::GeomDataSource& gds);
	virtual ~ViewGDS();
	virtual void draw(TPad& pad);
	virtual void update();
	
    };

}

#endif
