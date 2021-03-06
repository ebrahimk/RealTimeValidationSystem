function listener()
{
  console.log(this.responseText);
}

function sendStuff(someText)
{
  var hostname = document.getElementById("hostname").value
  if (hostname == "")
  {
    alert("Please enter a hostname")
    return
  }

  var xhttp = new XMLHttpRequest();
  xhttp.addEventListener("load", listener);
  xhttp.open("POST", "http://" + hostname, true);
  xhttp.send(someText); 
}

function freeze()
{
  var type_sel = document.getElementById("FreezeNumber").value
  var FreezeCommand = document.getElementById("FreezeCommand").value
  var FTime = document.getElementById("FTime").value
  command = type_sel + "," + FreezeCommand + "," + FTime
  console.log("Sending command " + command)
  sendStuff(command)
}

function discoloration()
{
  var type_sel = document.getElementById("WhiteNumber").value
  var white_command = document.getElementById("WhiteCommand").value
  var WTime = document.getElementById("WTime").value
  var shade = document.getElementById("shade").value
  var command = type_sel + "," + white_command + "," + WTime + "," + shade
  console.log("Sending command " + command)
  sendStuff(command)
}


function tx()
{
  var type_sel = document.getElementById("TranslateNumber").value
  var TranslateCommand = document.getElementById("TranslateCommand").value
  var TTime = document.getElementById("TTime").value
  var x_offset = document.getElementById("x_offset").value
  var y_offset = document.getElementById("y_offset").value
  command = type_sel + "," + TranslateCommand + "," + TTime + "," + x_offset + "," + y_offset
  console.log("Sending command " + command)
  sendStuff(command)
}