
let df = 'diffeq.csv';

d3.csv(df).then(function(loadedData){

    let data1 = [];
    let data2 = [];
    let labels = [];

    for(let i = 0;i<loadedData.length;i++){

        console.log(loadedData[i]);

        let t =  loadedData[i].t;
        let y1 = loadedData[i].y;
        let y2 = loadedData[i].w;

        labels.push(t);
        data1.push(y1);
        data2.push(y2);

    }

    var ds1 = {
        label: "I1",
        data: data1,
        fill: false,
        pointRadius : 0,
        pointHoverRadius : 0,
        borderColor : 'rgb(234,82,49)',
        tension : 0.4
    }

    var ds2 = {
        label : "I2",
        data : data2,
        fill : false,
        pointRadius : 0,
        pointHoverRadius : 0,
        borderColor : 'rgb(36,87,232)',
        tension : 0.4
    }


    let options = {
        type: 'line',
        data: {
            labels : labels,
            datasets : [ds1,ds2]
        },
    
    };

    let chart = new Chart(document.getElementById('canvas'),options);

});

