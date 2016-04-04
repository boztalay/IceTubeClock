<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="boztalay">
<packages>
<package name="ZIF-28">
<pad name="15" x="-16.51" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="16" x="-13.97" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="18" x="-8.89" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="17" x="-11.43" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="19" x="-6.35" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="20" x="-3.81" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="21" x="-1.27" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="22" x="1.27" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="23" x="3.81" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="24" x="6.35" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="25" x="8.89" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="26" x="11.43" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="27" x="13.97" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="28" x="16.51" y="-3.81" drill="0.8" diameter="1.6764"/>
<pad name="14" x="-16.51" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="13" x="-13.97" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="12" x="-11.43" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="11" x="-8.89" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="10" x="-6.35" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="9" x="-3.81" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="8" x="-1.27" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="7" x="1.27" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="6" x="3.81" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="5" x="6.35" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="4" x="8.89" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="3" x="11.43" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="2" x="13.97" y="3.81" drill="0.8" diameter="1.6764"/>
<pad name="1" x="16.51" y="3.81" drill="0.8" diameter="1.6764"/>
<wire x1="-21.59" y1="7.62" x2="-21.59" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-21.59" y1="-7.62" x2="25.4" y2="-7.62" width="0.127" layer="21"/>
<wire x1="25.4" y1="-7.62" x2="25.4" y2="7.62" width="0.127" layer="21"/>
<wire x1="25.4" y1="7.62" x2="-21.59" y2="7.62" width="0.127" layer="21"/>
<circle x="19.05" y="5.08" radius="0.898025" width="0.127" layer="21"/>
</package>
<package name="IV11-BOOST-SUPPLY">
<pad name="VCC" x="-5.08" y="0" drill="1" diameter="2.1844"/>
<pad name="PWM" x="-2.54" y="0" drill="1" diameter="2.1844"/>
<pad name="GND" x="0" y="0" drill="1" diameter="2.1844"/>
<pad name="FBK" x="2.54" y="0" drill="1" diameter="2.1844"/>
<pad name="BST" x="5.08" y="0" drill="1" diameter="2.1844"/>
<wire x1="-6.985" y1="0.635" x2="-5.715" y2="1.905" width="0.127" layer="21"/>
<wire x1="-5.715" y1="1.905" x2="-4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="-4.445" y1="1.905" x2="-3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.175" y1="1.905" x2="-1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="-1.905" y1="1.905" x2="-1.27" y2="1.27" width="0.127" layer="21"/>
<wire x1="-1.27" y1="1.27" x2="-0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="-0.635" y1="1.905" x2="0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="0.635" y1="1.905" x2="1.27" y2="1.27" width="0.127" layer="21"/>
<wire x1="1.27" y1="1.27" x2="1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="1.905" y1="1.905" x2="3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="3.175" y1="1.905" x2="3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="3.81" y1="1.27" x2="4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="4.445" y1="1.905" x2="5.715" y2="1.905" width="0.127" layer="21"/>
<wire x1="5.715" y1="1.905" x2="6.985" y2="0.635" width="0.127" layer="21"/>
<wire x1="6.985" y1="0.635" x2="6.985" y2="-0.635" width="0.127" layer="21"/>
<wire x1="6.985" y1="-0.635" x2="5.715" y2="-1.905" width="0.127" layer="21"/>
<wire x1="5.715" y1="-1.905" x2="4.445" y2="-1.905" width="0.127" layer="21"/>
<wire x1="4.445" y1="-1.905" x2="3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="3.81" y1="-1.27" x2="3.175" y2="-1.905" width="0.127" layer="21"/>
<wire x1="3.175" y1="-1.905" x2="1.905" y2="-1.905" width="0.127" layer="21"/>
<wire x1="1.905" y1="-1.905" x2="1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="0.635" y2="-1.905" width="0.127" layer="21"/>
<wire x1="0.635" y1="-1.905" x2="-0.635" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-0.635" y1="-1.905" x2="-1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-1.27" x2="-1.905" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-1.905" x2="-3.175" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-3.175" y1="-1.905" x2="-3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-1.27" x2="-4.445" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-4.445" y1="-1.905" x2="-5.715" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-1.905" x2="-6.985" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-6.985" y1="-0.635" x2="-6.985" y2="0.635" width="0.127" layer="21"/>
<text x="-5.08" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">VCC</text>
<text x="-2.54" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">PWM</text>
<text x="0" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">GND</text>
<text x="2.54" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">FBK</text>
<text x="5.08" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">BST</text>
<wire x1="-35.56" y1="-7.62" x2="11.43" y2="-7.62" width="0.127" layer="21"/>
<wire x1="11.43" y1="-7.62" x2="11.43" y2="30.48" width="0.127" layer="21"/>
<wire x1="-35.56" y1="-7.62" x2="-35.56" y2="46.99" width="0.127" layer="21"/>
<wire x1="11.43" y1="30.48" x2="-5.08" y2="46.99" width="0.127" layer="21"/>
<wire x1="-5.08" y1="46.99" x2="-35.56" y2="46.99" width="0.127" layer="21"/>
<circle x="-33.02" y="44.45" radius="1.79605" width="0.127" layer="21"/>
<circle x="-33.02" y="-5.08" radius="1.79605" width="0.127" layer="21"/>
<circle x="-6.35" y="44.45" radius="1.79605" width="0.127" layer="21"/>
</package>
<package name="IV-11-CARRIER">
<pad name="E" x="0" y="0" drill="1" diameter="2.1844"/>
<pad name="F" x="2.54" y="0" drill="1" diameter="2.1844"/>
<pad name="G" x="5.08" y="0" drill="1" diameter="2.1844"/>
<pad name="H" x="7.62" y="0" drill="1" diameter="2.1844"/>
<pad name="GRID" x="10.16" y="0" drill="1" diameter="2.1844"/>
<pad name="FIL_" x="12.7" y="0" drill="1" diameter="2.1844"/>
<pad name="D" x="-2.54" y="0" drill="1" diameter="2.1844"/>
<pad name="C" x="-5.08" y="0" drill="1" diameter="2.1844"/>
<pad name="B" x="-7.62" y="0" drill="1" diameter="2.1844"/>
<pad name="A" x="-10.16" y="0" drill="1" diameter="2.1844"/>
<pad name="FIL" x="-12.7" y="0" drill="1" diameter="2.1844"/>
<wire x1="-14.605" y1="0.635" x2="-13.335" y2="1.905" width="0.127" layer="21"/>
<wire x1="-13.335" y1="1.905" x2="-12.065" y2="1.905" width="0.127" layer="21"/>
<wire x1="-12.065" y1="1.905" x2="-11.43" y2="1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="1.27" x2="-10.795" y2="1.905" width="0.127" layer="21"/>
<wire x1="-10.795" y1="1.905" x2="-9.525" y2="1.905" width="0.127" layer="21"/>
<wire x1="-9.525" y1="1.905" x2="-8.89" y2="1.27" width="0.127" layer="21"/>
<wire x1="-8.89" y1="1.27" x2="-8.255" y2="1.905" width="0.127" layer="21"/>
<wire x1="-8.255" y1="1.905" x2="-6.985" y2="1.905" width="0.127" layer="21"/>
<wire x1="-6.985" y1="1.905" x2="-6.35" y2="1.27" width="0.127" layer="21"/>
<wire x1="-6.35" y1="1.27" x2="-5.715" y2="1.905" width="0.127" layer="21"/>
<wire x1="-5.715" y1="1.905" x2="-4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="-4.445" y1="1.905" x2="-3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="-3.175" y1="1.905" x2="-1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="-1.905" y1="1.905" x2="-1.27" y2="1.27" width="0.127" layer="21"/>
<wire x1="-1.27" y1="1.27" x2="-0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="-0.635" y1="1.905" x2="0.635" y2="1.905" width="0.127" layer="21"/>
<wire x1="0.635" y1="1.905" x2="1.27" y2="1.27" width="0.127" layer="21"/>
<wire x1="1.27" y1="1.27" x2="1.905" y2="1.905" width="0.127" layer="21"/>
<wire x1="1.905" y1="1.905" x2="3.175" y2="1.905" width="0.127" layer="21"/>
<wire x1="3.175" y1="1.905" x2="3.81" y2="1.27" width="0.127" layer="21"/>
<wire x1="3.81" y1="1.27" x2="4.445" y2="1.905" width="0.127" layer="21"/>
<wire x1="4.445" y1="1.905" x2="5.715" y2="1.905" width="0.127" layer="21"/>
<wire x1="5.715" y1="1.905" x2="6.35" y2="1.27" width="0.127" layer="21"/>
<wire x1="6.35" y1="1.27" x2="6.985" y2="1.905" width="0.127" layer="21"/>
<wire x1="6.985" y1="1.905" x2="8.255" y2="1.905" width="0.127" layer="21"/>
<wire x1="8.255" y1="1.905" x2="8.89" y2="1.27" width="0.127" layer="21"/>
<wire x1="8.89" y1="1.27" x2="9.525" y2="1.905" width="0.127" layer="21"/>
<wire x1="9.525" y1="1.905" x2="10.795" y2="1.905" width="0.127" layer="21"/>
<wire x1="10.795" y1="1.905" x2="11.43" y2="1.27" width="0.127" layer="21"/>
<wire x1="11.43" y1="1.27" x2="12.065" y2="1.905" width="0.127" layer="21"/>
<wire x1="12.065" y1="1.905" x2="13.335" y2="1.905" width="0.127" layer="21"/>
<wire x1="13.335" y1="1.905" x2="14.605" y2="0.635" width="0.127" layer="21"/>
<wire x1="14.605" y1="0.635" x2="14.605" y2="-0.635" width="0.127" layer="21"/>
<wire x1="14.605" y1="-0.635" x2="13.335" y2="-1.905" width="0.127" layer="21"/>
<wire x1="13.335" y1="-1.905" x2="12.065" y2="-1.905" width="0.127" layer="21"/>
<wire x1="12.065" y1="-1.905" x2="11.43" y2="-1.27" width="0.127" layer="21"/>
<wire x1="11.43" y1="-1.27" x2="10.795" y2="-1.905" width="0.127" layer="21"/>
<wire x1="10.795" y1="-1.905" x2="9.525" y2="-1.905" width="0.127" layer="21"/>
<wire x1="9.525" y1="-1.905" x2="8.89" y2="-1.27" width="0.127" layer="21"/>
<wire x1="8.89" y1="-1.27" x2="8.255" y2="-1.905" width="0.127" layer="21"/>
<wire x1="8.255" y1="-1.905" x2="6.985" y2="-1.905" width="0.127" layer="21"/>
<wire x1="6.985" y1="-1.905" x2="6.35" y2="-1.27" width="0.127" layer="21"/>
<wire x1="6.35" y1="-1.27" x2="5.715" y2="-1.905" width="0.127" layer="21"/>
<wire x1="5.715" y1="-1.905" x2="4.445" y2="-1.905" width="0.127" layer="21"/>
<wire x1="4.445" y1="-1.905" x2="3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="3.81" y1="-1.27" x2="3.175" y2="-1.905" width="0.127" layer="21"/>
<wire x1="3.175" y1="-1.905" x2="1.905" y2="-1.905" width="0.127" layer="21"/>
<wire x1="1.905" y1="-1.905" x2="1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="0.635" y2="-1.905" width="0.127" layer="21"/>
<wire x1="0.635" y1="-1.905" x2="-0.635" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-0.635" y1="-1.905" x2="-1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-1.27" x2="-1.905" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-1.905" x2="-3.175" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-3.175" y1="-1.905" x2="-3.81" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-1.27" x2="-4.445" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-4.445" y1="-1.905" x2="-5.715" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-1.905" x2="-6.35" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-1.27" x2="-6.985" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-6.985" y1="-1.905" x2="-8.255" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-8.255" y1="-1.905" x2="-8.89" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-1.27" x2="-9.525" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-9.525" y1="-1.905" x2="-10.795" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-10.795" y1="-1.905" x2="-11.43" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-1.27" x2="-12.065" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-12.065" y1="-1.905" x2="-13.335" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-13.335" y1="-1.905" x2="-14.605" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-14.605" y1="-0.635" x2="-14.605" y2="0.635" width="0.127" layer="21"/>
<text x="-12.7" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">FIL</text>
<text x="-10.16" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">A</text>
<text x="-7.62" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">B</text>
<text x="-5.08" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">C</text>
<text x="-2.54" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">D</text>
<text x="0" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">E</text>
<text x="2.54" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">F</text>
<text x="5.08" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">G</text>
<text x="7.62" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">H</text>
<text x="10.16" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">GRID</text>
<text x="12.7" y="2.54" size="1.27" layer="21" rot="R90" align="center-left">FIL</text>
<wire x1="-15.24" y1="-2.54" x2="15.24" y2="-2.54" width="0.127" layer="21"/>
<wire x1="15.24" y1="-2.54" x2="15.24" y2="24.13" width="0.127" layer="21"/>
<wire x1="15.24" y1="24.13" x2="-15.24" y2="24.13" width="0.127" layer="21"/>
<wire x1="-15.24" y1="24.13" x2="-15.24" y2="-2.54" width="0.127" layer="21"/>
<circle x="-12.7" y="21.59" radius="1.79605" width="0.127" layer="21"/>
<circle x="12.7" y="21.59" radius="1.79605" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="ATMEGA168">
<pin name="PC6" x="-10.16" y="15.24" length="middle"/>
<pin name="PD0" x="-10.16" y="12.7" length="middle"/>
<pin name="PD1" x="-10.16" y="10.16" length="middle"/>
<pin name="PD2" x="-10.16" y="7.62" length="middle"/>
<pin name="PD3" x="-10.16" y="5.08" length="middle"/>
<pin name="PD4" x="-10.16" y="2.54" length="middle"/>
<pin name="VCC" x="-10.16" y="0" length="middle"/>
<pin name="GND" x="-10.16" y="-2.54" length="middle"/>
<pin name="PB6" x="-10.16" y="-5.08" length="middle"/>
<pin name="PB7" x="-10.16" y="-7.62" length="middle"/>
<pin name="PD5" x="-10.16" y="-10.16" length="middle"/>
<pin name="PD6" x="-10.16" y="-12.7" length="middle"/>
<pin name="PD7" x="-10.16" y="-15.24" length="middle"/>
<pin name="PB0" x="-10.16" y="-17.78" length="middle"/>
<pin name="PB1" x="17.78" y="-17.78" length="middle" rot="R180"/>
<pin name="PB2" x="17.78" y="-15.24" length="middle" rot="R180"/>
<pin name="PB3" x="17.78" y="-12.7" length="middle" rot="R180"/>
<pin name="PB4" x="17.78" y="-10.16" length="middle" rot="R180"/>
<pin name="PB5" x="17.78" y="-7.62" length="middle" rot="R180"/>
<pin name="AVCC" x="17.78" y="-5.08" length="middle" rot="R180"/>
<pin name="AREF" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="GND_" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="PC0" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="PC1" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="PC2" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="PC3" x="17.78" y="10.16" length="middle" rot="R180"/>
<pin name="PC4" x="17.78" y="12.7" length="middle" rot="R180"/>
<pin name="PC5" x="17.78" y="15.24" length="middle" rot="R180"/>
<wire x1="-5.08" y1="17.78" x2="-5.08" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-20.32" x2="12.7" y2="-20.32" width="0.254" layer="94"/>
<wire x1="12.7" y1="-20.32" x2="12.7" y2="17.78" width="0.254" layer="94"/>
<wire x1="12.7" y1="17.78" x2="-5.08" y2="17.78" width="0.254" layer="94"/>
</symbol>
<symbol name="IV11-BOOST-SUPPLY">
<pin name="VCC" x="-5.08" y="-5.08" length="middle" rot="R90"/>
<pin name="PWM" x="-2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="GND" x="0" y="-5.08" length="middle" rot="R90"/>
<pin name="FBK" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="BST" x="5.08" y="-5.08" length="middle" rot="R90"/>
<wire x1="-7.62" y1="0" x2="7.62" y2="0" width="0.254" layer="94"/>
<wire x1="7.62" y1="0" x2="7.62" y2="7.62" width="0.254" layer="94"/>
<wire x1="7.62" y1="7.62" x2="-7.62" y2="7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="7.62" x2="-7.62" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="IV-11-CARRIER">
<pin name="FIL" x="-12.7" y="-5.08" length="middle" rot="R90"/>
<pin name="A" x="-10.16" y="-5.08" length="middle" rot="R90"/>
<pin name="B" x="-7.62" y="-5.08" length="middle" rot="R90"/>
<pin name="C" x="-5.08" y="-5.08" length="middle" rot="R90"/>
<pin name="D" x="-2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="E" x="0" y="-5.08" length="middle" rot="R90"/>
<pin name="F" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="G" x="5.08" y="-5.08" length="middle" rot="R90"/>
<pin name="H" x="7.62" y="-5.08" length="middle" rot="R90"/>
<pin name="GRID" x="10.16" y="-5.08" length="middle" rot="R90"/>
<pin name="FIL_" x="12.7" y="-5.08" length="middle" rot="R90"/>
<wire x1="-15.24" y1="-2.54" x2="15.24" y2="-2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-2.54" x2="15.24" y2="10.16" width="0.254" layer="94"/>
<wire x1="15.24" y1="10.16" x2="-15.24" y2="10.16" width="0.254" layer="94"/>
<wire x1="-15.24" y1="10.16" x2="-15.24" y2="-2.54" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ATMEGA168-ZIF-28">
<gates>
<gate name="G$1" symbol="ATMEGA168" x="-3.81" y="1.778"/>
</gates>
<devices>
<device name="" package="ZIF-28">
<connects>
<connect gate="G$1" pin="AREF" pad="21"/>
<connect gate="G$1" pin="AVCC" pad="20"/>
<connect gate="G$1" pin="GND" pad="8"/>
<connect gate="G$1" pin="GND_" pad="22"/>
<connect gate="G$1" pin="PB0" pad="14"/>
<connect gate="G$1" pin="PB1" pad="15"/>
<connect gate="G$1" pin="PB2" pad="16"/>
<connect gate="G$1" pin="PB3" pad="17"/>
<connect gate="G$1" pin="PB4" pad="18"/>
<connect gate="G$1" pin="PB5" pad="19"/>
<connect gate="G$1" pin="PB6" pad="9"/>
<connect gate="G$1" pin="PB7" pad="10"/>
<connect gate="G$1" pin="PC0" pad="23"/>
<connect gate="G$1" pin="PC1" pad="24"/>
<connect gate="G$1" pin="PC2" pad="25"/>
<connect gate="G$1" pin="PC3" pad="26"/>
<connect gate="G$1" pin="PC4" pad="27"/>
<connect gate="G$1" pin="PC5" pad="28"/>
<connect gate="G$1" pin="PC6" pad="1"/>
<connect gate="G$1" pin="PD0" pad="2"/>
<connect gate="G$1" pin="PD1" pad="3"/>
<connect gate="G$1" pin="PD2" pad="4"/>
<connect gate="G$1" pin="PD3" pad="5"/>
<connect gate="G$1" pin="PD4" pad="6"/>
<connect gate="G$1" pin="PD5" pad="11"/>
<connect gate="G$1" pin="PD6" pad="12"/>
<connect gate="G$1" pin="PD7" pad="13"/>
<connect gate="G$1" pin="VCC" pad="7"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="IV11-BOOST-SUPPLY">
<gates>
<gate name="G$1" symbol="IV11-BOOST-SUPPLY" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="IV11-BOOST-SUPPLY">
<connects>
<connect gate="G$1" pin="BST" pad="BST"/>
<connect gate="G$1" pin="FBK" pad="FBK"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="PWM" pad="PWM"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="IV-11-CARRIER">
<gates>
<gate name="G$1" symbol="IV-11-CARRIER" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="IV-11-CARRIER">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="B" pad="B"/>
<connect gate="G$1" pin="C" pad="C"/>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="E" pad="E"/>
<connect gate="G$1" pin="F" pad="F"/>
<connect gate="G$1" pin="FIL" pad="FIL"/>
<connect gate="G$1" pin="FIL_" pad="FIL_"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="GRID" pad="GRID"/>
<connect gate="G$1" pin="H" pad="H"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="boztalay" deviceset="ATMEGA168-ZIF-28" device=""/>
<part name="U$2" library="boztalay" deviceset="IV11-BOOST-SUPPLY" device=""/>
<part name="U$3" library="boztalay" deviceset="IV-11-CARRIER" device=""/>
<part name="U$4" library="boztalay" deviceset="IV-11-CARRIER" device=""/>
<part name="U$5" library="boztalay" deviceset="IV-11-CARRIER" device=""/>
<part name="U$6" library="boztalay" deviceset="IV-11-CARRIER" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="-33.02" y="-7.62"/>
<instance part="U$2" gate="G$1" x="33.02" y="-7.62"/>
<instance part="U$3" gate="G$1" x="-68.58" y="33.02"/>
<instance part="U$4" gate="G$1" x="-27.94" y="33.02"/>
<instance part="U$5" gate="G$1" x="20.32" y="33.02"/>
<instance part="U$6" gate="G$1" x="66.04" y="33.02"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
