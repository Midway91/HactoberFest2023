import './App.css';

import { Provider } from 'react-redux';
import store from './app/store';
import Mobile from './features/mobile/mobile';
import Userspage from './features/users/Userspage';
import Laptop from './features/laptop/laptop';

function App() {
  return (
    <div className="App">
      <Provider store={store}>
        <Laptop />
        <Mobile />
        <Userspage />

      </Provider>
    </div>
  );
}

export default App;
