

function InitializeMap() {
    var parks = [
        [35.16603,33.351713],
        [35.173088,33.353704],
        [35.17614,33.37192],
        [35.191283,33.385984],
        [35.187995,33.381473],
        [35.188968,33.378796],
        [35.173035,33.385668],
        [35.176541,33.389722],
        [35.156524,33.356362],
        [35.186661,33.394939],
        [35.170697,33.357756],
        [35.179029,33.378308],
        [35.189317,33.384098],
        [35.188951,33.387572],
        [35.164076,33.355986],
        [35.172662,33.370792],
        [35.176824,33.369299],
        [35.178984,33.336694],
        [35.157037,33.361887],
        [35.176541,33.389722],
        [35.170942,33.370037],
        [35.165085,33.350768],
        [35.169437,33.368123],
        [35.190958,33.388516],
        [35.185465,33.389262],
        [35.16715,33.395318],
        [35.156831,33.36282],
        [35.162064,33.359584],
        [35.164412,33.385991],
        [35.165616,33.376458],
        [35.17439,33.392808],
        [35.168536,33.365497],
    ];
    //alert("HERE GODDAMMIT!");
    var latlng = new google.maps.LatLng(35.133712, 33.388817);
    var myOptions = {
        zoom: 12,
        center: latlng,
        mapTypeId: google.maps.MapTypeId.ROADMAP
    };
    var map = new google.maps.Map(document.getElementById("map"), myOptions);
    //map.data.loadGeoJson('/Scripts/route1.json');
    //data = JSON.parse('route1.json');
    //console.log(data.name);
    //alert("HERE");
    //var marker;// = new google.maps.Marker({
    //    position: latlng,
    //    map: map
    //});
   
    for (var i = 0; i < parks.length; i++) {
        //alert(parks[i][0]);
        var marker = new google.maps.Marker({
            position: new google.maps.LatLng(parks[i][0], parks[i][1]),
            map: map,
            icon: bus_stop_icon
        });
        //google.maps.event.addListener(marker, 'click', (function (marker, i) {
        //    return function () {
        //        //infowindow.setContent(parks[i][0]);
        //        infowindow.open(map, marker);
        //    };
        //})(marker, i));
    }
}

//markersArray = [];
window.onload = InitializeMap;