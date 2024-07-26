function toggleLED() {
    fetch('/toggle')
      .then(response => response.text())
      .then(estado => {
        document.getElementById("estado").innerHTML = estado;
      });
  }
  
  function actualizarEstado() {
    fetch('/estado')
      .then(response => response.text())
      .then(estado => {
        document.getElementById("estado").innerHTML = estado;
      });
  }
  
  // Actualizar el estado cada segundo
  setInterval(actualizarEstado, 1000);