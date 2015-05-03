#!/usr/bin/env python

import ROOT

# fixme: shouldn't need this
ROOT.gSystem.Load("libWireCellNavDict")
ROOT.gSystem.Load("libWireCellRootVisDict")

ViewGDS = ROOT.WireCellRootVis.ViewGDS



class TestView(object):
    def __init__(self, pad = None):
        if not pad:
            pad = ROOT.TCanvas()
        self.pad = pad
        self.gds = ROOT.make_example_gds(100.0)
        self.view = ViewGDS(self.gds)
        self.view.draw(self.pad)
        return
        


