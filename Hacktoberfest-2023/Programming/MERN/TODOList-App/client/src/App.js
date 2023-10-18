import React, { useEffect, useState } from 'react';
import './App.css'
import Head from './todoComponent/Head';
import DataAdder from './todoComponent/DataAdder';
import ShowData from './todoComponent/ShowData';
import axios from 'axios';

const App = () => {
  const host = 'https://mern-todo-list-backend.onrender.com';
  const [item, setItem] = useState({ data: '' });
  const [addData, setAddData] = useState([]);
  const [holderText, setHolderText] = useState("Add Item");
  const [deleted, setDeleted] = useState(false);

  useEffect(() => {
    axios
      .get(`${host}/api/data`)
      .then((res) => {
        setAddData(res.data);
        setDeleted(false);

      })
      .catch((err) => {
        console.log(err);
      });
  }, [item, deleted]);

  const addItem = () => {
    if (item.data !== "") {
      axios
        .post(`${host}/api/data`, item)
        .then((res) => {
          setItem({ data: '' });
          setHolderText("Add Item");
          console.log(res.data.message);
        })
        .catch((err) => {
          console.log("Error couldn't add Item");
          console.error(err.message);
        });
    } else {
      setHolderText("Can't Empty");
    }
  }

  const deleteItem = (id) => {
    axios.delete(`${host}/api/data/${id}`);
    setDeleted(true);
  }

  return (
    <>
      <div className="container">
        <div className="center_container">
          <Head />
          <div className="body">
            <DataAdder item={item} setItem={setItem} click={addItem} placeholderText={holderText} />
            <ol className="lists">
              {
                addData.map((item) => {
                  return <ShowData key={item._id} item={item} onSelect={deleteItem} />
                })
              }
            </ol>
          </div>
        </div>
      </div>
    </>
  );
}

export default App;