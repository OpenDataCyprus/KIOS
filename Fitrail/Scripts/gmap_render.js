

function InitializeMap() {
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
    var markersArray = [];
    google.maps.event.addListener(map, 'click', function (event) {
        //if(typeof marker =='undefined'){
        //     marker = new google.maps.Marker({
        //        position: event.latLng,
        //        map: map
        //    });
        //} else {
        //if (marker) {
        //    deleteOver
        //    marker = marker.setPosition(event.latLng);
        //} else {
        //    marker = new google.maps.Marker({
        //        position: latlng,
        //        map: map
        //    });
        //}
            
        //}

        if (markersArray.length != 0) {
            for (var i = 0; i < markersArray.length; i++) {
                markersArray[i].setMap(null);
            }
            markersArray.length = 0;
            markersArray = [];
        }
        var marker = new google.maps.Marker({
            position: event.latLng,
            map: map
        });
        markersArray.push(marker);
        //$("#lat").empty();
        //$("#lat").append(event.latLng.lat());
        document.getElementById('lat').value = event.latLng.lat();
        document.getElementById('lon').value = event.latLng.lng();


       
    });
}

//markersArray = [];
window.onload = InitializeMap;